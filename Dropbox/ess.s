	.file	"ess.c"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	leal	.L.str, %eax
	movl	$0, -4(%ebp)
	movl	%eax, (%esp)
	calll	printf
	movl	%eax, -16(%ebp)         # 4-byte Spill
	calll	GetString
	leal	.L.str, %ecx
	movl	%eax, -8(%ebp)
	movl	%ecx, (%esp)
	calll	printf
	movl	%eax, -20(%ebp)         # 4-byte Spill
	calll	GetString
	movl	%eax, -12(%ebp)
	cmpl	$0, -8(%ebp)
	je	.LBB0_6
# BB#1:
	cmpl	$0, -12(%ebp)
	je	.LBB0_6
# BB#2:
	movl	-8(%ebp), %eax
	movl	-12(%ebp), %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	strcmp
	cmpl	$0, %eax
	jne	.LBB0_4
# BB#3:
	leal	.L.str1, %eax
	movl	%eax, (%esp)
	calll	printf
	movl	%eax, -24(%ebp)         # 4-byte Spill
	jmp	.LBB0_5
.LBB0_4:
	leal	.L.str2, %eax
	movl	%eax, (%esp)
	calll	printf
	movl	%eax, -28(%ebp)         # 4-byte Spill
.LBB0_5:
	jmp	.LBB0_6
.LBB0_6:
	movl	-4(%ebp), %eax
	addl	$40, %esp
	popl	%ebp
	ret
.Ltmp0:
	.size	main, .Ltmp0-main

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "taper la lettre\n"
	.size	.L.str, 17

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	 "\nbravo\n"
	.size	.L.str1, 8

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	 "\nechec \n"
	.size	.L.str2, 9


	.section	".note.GNU-stack","",@progbits
