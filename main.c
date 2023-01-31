#include <stdint.h>
#include <stdio.h>
#define USART3_IRQNO 39
int main(void)
{
	uint32_t *pISPR1=(uint32_t)0XE000E204;
	*pISPR1 |=(1<<(USART3_IRQNO %32));

	uint32_t *pISER1=(uint32_t*)0XE000E104;
	*pISER1 |=(1<<(USART3_IRQNO %32));
	for(;;);
}
void USART3_IRQHandler(void)
{
	printf("in handler");
}
