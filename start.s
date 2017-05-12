.section .startup
.code 32
.align 0
.global _start
.global __vector_reset
.global __vector_undefined
.global __vector_swi
.global __vector_prefetch_abort
.global __vector_data_abort
.global __vector_reserved
.global __vector_irq
.global __vector_fiq

_start:

ldr pc,_vector_reset
ldr pc,_vector_undefined
ldr pc,_vector_swi
ldr pc,_vector_prefetch_abort
ldr pc,_vector_data_abort
ldr pc,_vector_reserved
ldr pc,_vector_irq
ldr pc,_vector_fiq

.align 4
_vector_reset: .word __vector_reset
_vector_undefined: .word __vector_undefined
_vector_swi: .word __vector_swi
_vector_prefetch_abort: .word __vector_prefetch_abort
_vector_data_abort: .word __vector_data_abort
_vector_reserved: .word __vector_reserved
_vector_irq: .word __vector_irq
_vector_fiq: .word __vector_fiq

