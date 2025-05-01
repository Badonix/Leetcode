/**
 * @param {number[]} tasks
 * @param {number[]} workers
 * @param {number} pills
 * @param {number} strength
 * @return {number}
 */
function maxTaskAssign(
    tasks: number[],
    workers: number[],
    pills: number,
    pillStrength: number
): number {
    const taskCount = tasks.length;
    const workerCount = workers.length;

    const sortedTasks = new Uint32Array(tasks);
    sortedTasks.sort();
    const sortedWorkers = new Uint32Array(workers);
    sortedWorkers.sort();

    if (pills === 0 || pillStrength === 0) {
        let taskPtr = taskCount - 1;
        let workerPtr = workerCount - 1;
        let completed = 0;
        while (taskPtr >= 0 && workerPtr >= 0) {
            if (sortedWorkers[workerPtr] >= sortedTasks[taskPtr]) {
                completed++;
                workerPtr--;
                taskPtr--;
            } else {
                taskPtr--;
            }
        }
        return completed;
    }

    const boostedWorkers = new Uint32Array(workerCount);
    for (let i = 0; i < workerCount; i++) {
        boostedWorkers[i] = sortedWorkers[i] + pillStrength;
    }

    if (pills >= workerCount) {
        let taskPtr = taskCount - 1;
        let boostPtr = workerCount - 1;
        let completed = 0;
        while (taskPtr >= 0 && boostPtr >= 0) {
            if (boostedWorkers[boostPtr] >= sortedTasks[taskPtr]) {
                completed++;
                boostPtr--;
                taskPtr--;
            } else {
                taskPtr--;
            }
        }
        return completed;
    }

    const candidateBuffer = new Uint32Array(workerCount);
    const requirements = sortedTasks;
    const originals = sortedWorkers;
    const boosted = boostedWorkers;

    let low = 0;
    let high = Math.min(taskCount, workerCount);
    let best = 0;

    while (low <= high) {
        const trialCount = (low + high) >>> 1;
        if (trialCount === 0) {
            best = 0;
            low = 1;
            continue;
        }

        const windowStart = workerCount - trialCount;
        let workerPtr = workerCount - 1;
        let head = 0;
        let tail = 0;
        let remainingPills = pills;
        let feasible = true;

        for (let taskIdx = trialCount - 1; taskIdx >= 0; taskIdx--) {
            const need = requirements[taskIdx];

            while (workerPtr >= windowStart && boosted[workerPtr] >= need) {
                candidateBuffer[tail++] = originals[workerPtr--];
            }

            if (head === tail) {
                feasible = false;
                break;
            }

            if (candidateBuffer[head] >= need) {
                head++;
            } else {
                tail--;
                if (--remainingPills < 0) {
                    feasible = false;
                    break;
                }
            }
        }

        if (feasible) {
            best = trialCount;
            low = trialCount + 1;
        } else {
            high = trialCount - 1;
        }
    }

    return best;
}