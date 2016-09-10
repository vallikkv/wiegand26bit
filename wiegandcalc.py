
###################################
###	Author:	Vallinayagam.K	###
###	Date:	09/10/2016	###
###################################

#!/usr/bin/python

import sys


class conversion:

    def __init__(self):
        if len(sys.argv) != 3:
            print "Enter facility code & card number in the respective fields without space! "
        else:
            self.facility = int(sys.argv[1])
            self.cardnumber = int(sys.argv[2])

    def facilitycode(self):
        self.facbits = bin(self.facility).split("b")[1]
        self.lenfacilitybits = len(self.facbits)
        self.facbitdiff = 8 - self.lenfacilitybits
        if self.facbitdiff != 0:
            self.facbits = (self.facbitdiff*"0")+str(self.facbits)
            return self.facbits
        else:
            return self.facbits

    def card(self):
        self.cardbits = bin(self.cardnumber).split("b")[1]
        self.lencardbits = len(self.cardbits)
        self.cardbitdiff = 16 - self.lencardbits
        if self.cardbitdiff != 0:
            self.cardbits = (self.cardbitdiff*"0")+str(self.cardbits)
            return self.cardbits
        else:
            return self.cardbits

    def parity(self):
        self.oddparity, self.evenparity = 0,0
        self.totalbits = self.facilitycode() + self.card()
        self.even,self.odd = self.totalbits[:len(self.totalbits)/2], self.totalbits[len(self.totalbits)/2:]

        #counting no of bits as "1" in odd
        for i in self.odd:
            if i == "1":
                self.oddparity+=1
        if self.oddparity % 2 != 0:
            self.odd = self.odd + "0"
        else:
            self.odd = self.odd + "1"


        #counting no of bits as "1" in even
        for i in self.even:
            if i == "1":
                self.evenparity+=1
        if self.evenparity % 2 == 0:
            self.even = "0" + self.even
        else:
            self.even = "1" + self.even

        return int(self.even+self.odd, 2)


if __name__ == "__main__":
    a = conversion()
    a.facilitycode()
    a.card()
    print a.parity()
