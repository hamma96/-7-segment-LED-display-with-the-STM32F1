/**
  ******************************************************************************
  * @file    EXTI/main.c 
  * @author  Mohamed Hssairi
  * @version V1.0.0
  * @date    28/03/2019
  * @brief   Main program body
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"


/** @addtogroup Examples
  * @{
  */




/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
	
	
	*/
	/* Mohamed Hssairi II2D */
	/*definition des segments de l'afficheur */
#define SEGMENT_A GPIO_Pin_7
#define SEGMENT_B GPIO_Pin_6
#define SEGMENT_C GPIO_Pin_4
#define SEGMENT_D GPIO_Pin_2
#define SEGMENT_E GPIO_Pin_1
#define SEGMENT_F GPIO_Pin_9
#define SEGMENT_G GPIO_Pin_10

GPIO_InitTypeDef GPIO_InitStructure;
//Mohamed Hssairi II2D
void SegDisplay(uint16_t chiffre){
  
  switch(chiffre){
  case 0 : GPIO_SetBits(GPIOC, SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F );
           GPIO_ResetBits(GPIOC, SEGMENT_G );
            break ;
  case 1 : GPIO_SetBits(GPIOC,SEGMENT_B | SEGMENT_C );
             GPIO_ResetBits (GPIOC, SEGMENT_A | SEGMENT_D | SEGMENT_E | SEGMENT_F| SEGMENT_G);
            break ;
  case 2 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_B | SEGMENT_G | SEGMENT_D | SEGMENT_E );
             GPIO_ResetBits (GPIOC, SEGMENT_C | SEGMENT_F );
            break ;
            
  case 3 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D| SEGMENT_G );
             GPIO_ResetBits (GPIOC, SEGMENT_E | SEGMENT_F );
            break ;
		case 4 : GPIO_SetBits(GPIOC,SEGMENT_B | SEGMENT_C | SEGMENT_F| SEGMENT_G  );
             GPIO_ResetBits (GPIOC, SEGMENT_A | SEGMENT_D | SEGMENT_E );
            break ;
            
   case 5 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_F | SEGMENT_G  );
             GPIO_ResetBits (GPIOC, SEGMENT_B |  SEGMENT_E );
            break ;
            
            
   case 6 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_E| SEGMENT_F | SEGMENT_G  );
             GPIO_ResetBits (GPIOC, SEGMENT_B  );
            break ;
            
   case 7 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_B | SEGMENT_C   );
             GPIO_ResetBits (GPIOC, SEGMENT_E | SEGMENT_F | SEGMENT_G |  SEGMENT_D   );
            break ;
            
   case 8 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D |SEGMENT_E | SEGMENT_F | SEGMENT_G   );
            break ;
            
    case 9 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F | SEGMENT_G  );
             GPIO_ResetBits (GPIOC, SEGMENT_E   );
            break ;
    case 10 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_E | SEGMENT_F | SEGMENT_G  );
             GPIO_ResetBits (GPIOC, SEGMENT_D   );
            break ;
		case 11 : GPIO_SetBits(GPIOC,SEGMENT_F | SEGMENT_E | SEGMENT_D | SEGMENT_C | SEGMENT_G  );
             GPIO_ResetBits (GPIOC, SEGMENT_A|SEGMENT_B   );
            break ;
		case 12 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_F | SEGMENT_E | SEGMENT_D  );
             GPIO_ResetBits (GPIOC, SEGMENT_G|SEGMENT_B|SEGMENT_C   );
            break ;
		case 13 : GPIO_SetBits(GPIOC,SEGMENT_C | SEGMENT_B | SEGMENT_G | SEGMENT_D | SEGMENT_E   );
             GPIO_ResetBits (GPIOC, SEGMENT_A|SEGMENT_F   );
            break ;
		case 14 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_F | SEGMENT_G | SEGMENT_D | SEGMENT_E  );
             GPIO_ResetBits (GPIOC, SEGMENT_B|SEGMENT_C   );
            break ;
		case 15 : GPIO_SetBits(GPIOC,SEGMENT_A | SEGMENT_F | SEGMENT_G | SEGMENT_E  );
             GPIO_ResetBits (GPIOC, SEGMENT_D| SEGMENT_C|SEGMENT_B  );
            break ;
    default : GPIO_SetBits(GPIOC, SEGMENT_G  );
             GPIO_ResetBits (GPIOC,SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F | SEGMENT_E   );}}
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}
uint16_t i;
int main(void)
{ 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
		GPIO_Init(GPIOC, &GPIO_InitStructure );	
  while (1)
  {
		for(i=0;i<16;i++)
		{
			SegDisplay(i);
			Delay(0xAFFFF);
			}
	 }

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
