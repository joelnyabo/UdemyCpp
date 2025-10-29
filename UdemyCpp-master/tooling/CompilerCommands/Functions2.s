	.file	"Functions2.cc"
	.text
	.p2align 4
	.globl	_Z7is_eveni
	.def	_Z7is_eveni;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7is_eveni
_Z7is_eveni:
.LFB1773:
	.seh_endprologue
	movl	%ecx, %eax
	notl	%eax
	andl	$1, %eax
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1774:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I__Z7is_eveni;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z7is_eveni
_GLOBAL__sub_I__Z7is_eveni:
.LFB2239:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rbx
	movq	%rbx, %rcx
	call	_ZNSt8ios_base4InitC1Ev
	movq	.refptr.__dso_handle(%rip), %r8
	movq	.refptr._ZNSt8ios_base4InitD1Ev(%rip), %rcx
	movq	%rbx, %rdx
	addq	$32, %rsp
	popq	%rbx
	jmp	__cxa_atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z7is_eveni
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (GNU) 12.5.0"
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	__cxa_atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZNSt8ios_base4InitD1Ev, "dr"
	.globl	.refptr._ZNSt8ios_base4InitD1Ev
	.linkonce	discard
.refptr._ZNSt8ios_base4InitD1Ev:
	.quad	_ZNSt8ios_base4InitD1Ev
	.section	.rdata$.refptr.__dso_handle, "dr"
	.globl	.refptr.__dso_handle
	.linkonce	discard
.refptr.__dso_handle:
	.quad	__dso_handle
