function checkDistances(s, distance) {
  let alph = "abcdefghijklmnopqrstuvwxyz";
  let isValid = true;
  for (let i = 0; i < distance.length; i++) {
    let currentDistance = distance[i];
    let currentLetter = alph[i];

    if (!s.includes(alph[i])) {
      continue;
    }
    let firstOccurrence = -1;
    let secondOccurrence = -1;
    for (let j = 0; j < s.length; j++) {
      if (s[j] === currentLetter) {
        if (firstOccurrence === -1) {
          firstOccurrence = j;
        } else {
          secondOccurrence = j;
          break;
        }
      }
    }
    if (Math.abs(firstOccurrence - secondOccurrence) - 1 == currentDistance) {
      continue;
    } else {
      isValid = false;
      break;
    }
  }
  return isValid;
}