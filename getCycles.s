.align 32

.section .text
.globl getCycles
getCycles:
  push %ebx
  xor %eax, %eax

  cpuid
  rdtsc

  pop %ebx
  ret
