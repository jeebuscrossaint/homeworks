; CDA3203 Dr. Petrie Fall 2024
; Amarnath Patel Z23614792
; Part 1
ORG 100h
MOV AX, 0B800h
MOV DS, AX
;MOV CL, 'A' ; changed to P
MOV CL, 'P'
MOV CH, 1101_1111b
MOV BX, 15Eh
MOV [BX], CX
RET