class Solution {
public:

    struct eqT {
        int x;
        int free;
    };
    string solveEquation(string equation) {
        eqT simplified = simplifyEquation(equation);
        cout << simplified.x << "x " << simplified.free << endl;
        if(simplified.x == 0 && simplified.free == 0){
            return "Infinite solutions";
        }
        if(simplified.x == 0 && simplified.free != 0){
            return "No solution";
        }
        int answ =  (-1*simplified.free)/simplified.x;
        return "x=" + to_string(answ);
    }

    eqT simplify(string equation){
        int totalX = 0;
        int totalFree = 0;
        for(int i = 0; i < equation.size(); i++){
            if(equation[i] == 'x'){
                totalX += findXCoef(i, equation);
            }
        }

        for(int i = 0; i < equation.size(); i++){
            if((equation[i] == '+' && equation[i-1] != 'x') || (equation[i] == '-' && (i == 0 || equation[i-1] != 'x')) || (i == equation.size() - 1 && equation[i] != 'x')){
                totalFree += findFree(i, equation);
            }
        }
        eqT answ;
        answ.x = totalX;
        answ.free = totalFree;
        return answ;
    }

    int findFree(int i, string equation){
        if(equation[i] == '+' || equation[i] == '-'){
            i--;
        }
        string coef = "";
        bool isNegative = false;
        if(i == 0){
            return equation[i] - '0'; 
        }
        int j = i;
        while(j >= 0 && (equation[j] == '-' || equation[j] == '+' || isdigit(equation[j]))){
            if(equation[j] == '+' || equation[j] == '-'){
                isNegative = equation[j] == '-';
                break;
            }
            coef += equation[j];
            j--;
        }
        if(coef.empty()){
            return 0;
        }
        reverse(coef.begin(), coef.end());
        int answ = stoi(coef);
        return isNegative ? answ * -1 : answ;
    }


    int findXCoef(int i, string equation){
        if(i == 0){
            return 1;
        }
        if(i == 1){
            return equation[0] == '-' ? -1 : equation[0] - '0'; 
        }
        int j = i - 1;
        string coef = "";
        bool isNegative = false;
        while(j >= 0 && (equation[j] == '-' || equation[j] == '+' || isdigit(equation[j]))){
            if(equation[j] == '+' || equation[j] == '-'){
                isNegative = equation[j] == '-';
                break;
            }
            coef += equation[j];
            j--;
        }
        if(coef.empty()){
            return isNegative ? -1 : 1;
        }
        reverse(coef.begin(), coef.end());
        int answ = stoi(coef);
        return isNegative ? answ * -1 : answ;
    }

    eqT simplifyEquation(string equation){
        // both gonna have -2x+2 format
        int indexOfEqualSign = 0;
        for(int i = 0; i < equation.size(); i++){
            if(equation[i] == '='){
                indexOfEqualSign = i;
                break;
            }
        }
        eqT leftSide = simplify(equation.substr(0, indexOfEqualSign));
        eqT rightSide = simplify(equation.substr(indexOfEqualSign+1, equation.size() - indexOfEqualSign - 1));
        eqT answ;
        answ.x = leftSide.x - rightSide.x;
        answ.free = leftSide.free - rightSide.free;
        return answ;
    }
};
