	.file	"add.cpp"
	.text
	.p2align 4
	.globl	_Z2plRK1AS1_
	.type	_Z2plRK1AS1_, @function
_Z2plRK1AS1_:
.LFB14:
	.cfi_startproc
	movl	(%rsi), %eax
	addl	(%rdi), %eax
	movl	%eax, _ZZ2plRK1AS1_E3res(%rip)
	ret
	.cfi_endproc
.LFE14:
	.size	_Z2plRK1AS1_, .-_Z2plRK1AS1_
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d%d"
.LC1:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB15:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	_ZL1b(%rip), %rdx
	leaq	_ZL1a(%rip), %rsi
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rdi
	call	__isoc99_scanf@PLT
	movl	_ZL1b(%rip), %esi
	leaq	.LC1(%rip), %rdi
	xorl	%eax, %eax
	addl	_ZL1a(%rip), %esi
	movl	%esi, _ZZ2plRK1AS1_E3res(%rip)
	call	printf@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE15:
	.size	main, .-main
	.local	_ZZ2plRK1AS1_E3res
	.comm	_ZZ2plRK1AS1_E3res,4,4
	.local	_ZL1b
	.comm	_ZL1b,4,4
	.local	_ZL1a
	.comm	_ZL1a,4,4
	.ident	"GCC: (GNU) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
