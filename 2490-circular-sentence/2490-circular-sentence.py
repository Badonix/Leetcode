class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
            is_circular = True
            new_list = sentence.split(" ")
            if len(new_list) == 1:
                return sentence[0] == sentence[len(sentence) - 1]

            bolo_sityva = new_list[len(new_list) - 1]
            if bolo_sityva[len(bolo_sityva) - 1] != new_list[0][0]:
                return False

            for index, word in enumerate(new_list):
                if index + 1 == len(new_list):
                    break
                if word[len(word) - 1] != new_list[index + 1][0]:
                    is_circular = False
                    break

            return is_circular

        