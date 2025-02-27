function isValid(s: string): boolean {
  let opening = [];
  let closingCounter = 0;
  let openingCounter = 0;
  let isValid = true;
  for (let i = 0; i < s.length; i++) {
    if (s[i] == "[") {
      openingCounter++;
      opening.push("[");
    } else if (s[i] == "{") {
      openingCounter++;
      opening.push("{");
    } else if (s[i] == "(") {
      openingCounter++;
      opening.push("(");
    } else {
      closingCounter++;
      if (s[i] == "]") {
        if (opening.pop() != "[") {
          isValid = false;
          break;
        }
      } else if (s[i] == "}") {
        if (opening.pop() != "{") {
          isValid = false;
          break;
        }
      } else if (s[i] == ")") {
        if (opening.pop() != "(") {
          isValid = false;
          break;
        }
      }
    }
  }
  if (closingCounter != openingCounter) {
    isValid = false;
  }
  return isValid;
};