CSEG AT 0
MOV R5,#72H
MOV R6,#91H
ANL 05,#00FH
MOV A,R6
SWAP A
ORL A,#0FH
CPL A
ORL 05H,A
END
