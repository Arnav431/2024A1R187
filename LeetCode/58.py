class soluttion:    
    def lengthOfLastWord(self, s: str) -> int:
        s=s.split()
        return len(s[-1])
    

i=input(">\t")
print(soluttion().lengthOfLastWord(i))