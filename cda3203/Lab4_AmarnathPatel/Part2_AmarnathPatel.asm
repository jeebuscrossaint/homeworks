; CDA3203 Dr. Petrie Fall 2024
; Amarnath Patel Z23614792
; Part 2
ORG 100h ; required directive for 1 segment .com code

; put FIRST in AL register
MOV AL, FIRST

; put LAST in BL register
MOV BL, LAST

; Multiply AX = AL * BL
MUL BL

; put AX in RESULT
MOV RESULT, AX

RET ; required to return to the operating system

; Assembler Directives to define 3 Variables
FIRST DB ? ; defines but does not initialize FIRST
LAST DB ? ; defines but does not initialize LAST
RESULT DW ? ; defines but does not initialize
