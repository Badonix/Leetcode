function numberOfEmployeesWhoMetTarget(hours: number[], target: number): number {
    let count = 0
    hours.forEach(el=> el >= target && count++)
    return count
};