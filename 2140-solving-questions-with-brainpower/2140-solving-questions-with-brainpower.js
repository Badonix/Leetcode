/**
 * @param {number[][]} questions
 * @return {number}
 */
var mostPoints = function(questions) {
    if(questions.length == 0){
        return 0;
    }
    if(questions.length == 1){
        return questions[0][0]
    }

    return Math.max(questions[0][0] + mostPoints(questions.slice(questions[0][1] + 1)), mostPoints(questions.slice(1)))
};