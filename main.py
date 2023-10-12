import enchant

def suggestWords(word):
    dictionary = enchant.Dict("en_US")
    if dictionary.check(word):
        return word
    else:
        suggestions = dictionary.suggest(word)[:5]
        if len(suggestions) > 0:
            print("\tDid you mean one of these words?")
            for i, suggestion in enumerate(suggestions):
                print(f"{i+1}. {suggestion}")
            select = input("\tEnter the number of the suggested word\n (or press enter to keep your guess): ")
            if select.isdigit() and int(select) <= len(suggestions):
                return suggestions[int(select)-1]
        return None

with open("shared.txt", "r") as file:
    word = file.read().strip().lower()
    suggestedWord = suggestWords(word)
    if suggestedWord:
        with open("check.txt", "w") as f:
            f.write(suggestedWord)
    else:
        print(f"{word} is not an English word and no suggestions were selected.")
