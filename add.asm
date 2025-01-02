.text # the text segment 

. globl main # can be called from anywhere

main :

ori $to , $0 , 0x03 

ori $t1 , $0 , 0x03

add $t2 , $t0 , $t1 