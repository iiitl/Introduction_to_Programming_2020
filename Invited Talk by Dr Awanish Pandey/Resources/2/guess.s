	.file	"guess.c"
	.comm	p,8,8
	.comm	val,4,4
	.section	.rodata
.LC0:
	.string	"In foo"
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	leaq	-4(%rbp), %rax
	movq	%rax, p(%rip)
	movq	p(%rip), %rax
	subq	$4, %rax
	movq	%rax, p(%rip)
	movq	p(%rip), %rax
	movl	(%rax), %eax
	movl	%eax, val(%rip)
	movl	$.LC0, %edi
	call	puts
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.section	.rodata
.LC1:
	.string	"In bar"
	.text
	.globl	bar
	.type	bar, @function
bar:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	leaq	-4(%rbp), %rax
	movq	%rax, p(%rip)
	movq	p(%rip), %rax
	subq	$4, %rax
	movq	%rax, p(%rip)
	movq	p(%rip), %rax
	movl	val(%rip), %edx
	movl	%edx, (%rax)
	movl	$.LC1, %edi
	call	puts
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	bar, .-bar
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$1, -8(%rbp)
	movl	$2, -4(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %edi
	call	foo
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	bar
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.5.0-12ubuntu1~16.04) 5.5.0 20171010"
	.section	.note.GNU-stack,"",@progbits
