#ifndef __LCD_H
#define __LCD_H

#include <Arduino.h>
#include <avr/pgmspace.h>
// #include <fonts.h>

/**
  ******************************************************************************
  * @file    fonts.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-February-2014
  * @brief   Header for fonts.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FONTS_H
#define __FONTS_H

/* Max size of bitmap will based on a font24 (17x24) */
#define MAX_HEIGHT_FONT         24
#define MAX_WIDTH_FONT          17
#define OFFSET_BITMAP           54

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

typedef struct _tFont
{    
  const uint8_t *table;
  uint16_t Width;
  uint16_t Height;
  
} sFONT;

extern sFONT Font24;
extern sFONT Font20;
extern sFONT Font16;
extern sFONT Font12;
extern sFONT Font8;

#ifdef __cplusplus
}
#endif
  
#endif /* __FONTS_H */
 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

#define	COLOR				uint16_t		//The variable type of the color
#define	POINT				uint16_t		//The type of coordinate
#define	LENGTH			uint16_t		//The type of coordinate	


/********************************************************************************
  function:
		Define the full screen height length of the display
********************************************************************************/
//#define LCD_1IN44
#define LCD_1IN8
#if defined(LCD_1IN44)
  #define LCD_WIDTH  128  //LCD width
  #define LCD_HEIGHT  128 //LCD height
#elif defined(LCD_1IN8)
  #define LCD_WIDTH  160  //LCD width
  #define LCD_HEIGHT  128 //LCD height
#endif

#define LCD_X 2
#define LCD_Y 1
#define LCD_X_MAXPIXEL  132  //LCD width maximum memory 
#define LCD_Y_MAXPIXEL  162 //LCD height maximum memory

/********************************************************************************
  function:
			scanning method
********************************************************************************/
typedef enum {
  L2R_U2D  = 0,	//The display interface is displayed , left to right, up to down
  L2R_D2U  ,
  R2L_U2D  ,
  R2L_D2U  ,

  U2D_L2R  ,
  U2D_R2L  ,
  D2U_L2R  ,
  D2U_R2L  ,
} LCD_SCAN_DIR;
#define SCAN_DIR_DFT  U2D_R2L  //Default scan direction = L2R_U2D

/********************************************************************************
  function:
	Defines the total number of rows in the display area
********************************************************************************/

typedef struct {
  LENGTH LCD_Dis_Column;	//COLUMN
  LENGTH LCD_Dis_Page;	//PAGE
  LCD_SCAN_DIR LCD_Scan_Dir;
  POINT LCD_X_Adjust;		//LCD x actual display position calibration
  POINT LCD_Y_Adjust;		//LCD y actual display position calibration
} LCD_DIS;
extern LCD_DIS sLCD_DIS;

/********************************************************************************
  function:
			dot pixel
********************************************************************************/
typedef enum {
  DOT_PIXEL_1X1  = 1,		// dot pixel 1 x 1
  DOT_PIXEL_2X2  , 		// dot pixel 2 X 2
  DOT_PIXEL_3X3  ,		// dot pixel 3 X 3
  DOT_PIXEL_4X4  ,		// dot pixel 4 X 4
  DOT_PIXEL_5X5  , 		// dot pixel 5 X 5
  DOT_PIXEL_6X6  , 		// dot pixel 6 X 6
  DOT_PIXEL_7X7  , 		// dot pixel 7 X 7
  DOT_PIXEL_8X8  , 		// dot pixel 8 X 8
} DOT_PIXEL;
#define DOT_PIXEL_DFT  DOT_PIXEL_1X1  //Default dot pilex

/********************************************************************************
  function:
			dot Fill style
********************************************************************************/
typedef enum {
  DOT_FILL_AROUND  = 1,		// dot pixel 1 x 1
  DOT_FILL_RIGHTUP  , 		// dot pixel 2 X 2
} DOT_STYLE;
#define DOT_STYLE_DFT  DOT_FILL_AROUND  //Default dot pilex
/********************************************************************************
  function:
			solid line and dotted line
********************************************************************************/
typedef enum {
  LINE_SOLID = 0,
  LINE_DOTTED,
} LINE_STYLE;

/********************************************************************************
  function:
			DRAW Internal fill
********************************************************************************/
typedef enum {
  DRAW_EMPTY = 0,
  DRAW_FULL,
} DRAW_FILL;

/********************************************************************************
  function:
			Defines commonly used colors for the display
********************************************************************************/
#define LCD_BACKGROUND		WHITE   //Default background color
#define FONT_BACKGROUND		WHITE   //Default font background color
#define FONT_FOREGROUND	    GRED    //Default font foreground color

#define WHITE          0xFFFF
#define BLACK          0x0000
#define BLUE           0x001F
#define BRED           0XF81F
#define GRED 		   0XFFE0
#define GBLUE		   0X07FF
#define RED            0xF800
#define MAGENTA        0xF81F
#define GREEN          0x07E0
#define CYAN           0x7FFF
#define YELLOW         0xFFE0
#define BROWN 		   0XBC40
#define BRRED 		   0XFC07
#define GRAY  		   0X8430


/********************************************************************************
  function:
			Macro definition variable name
********************************************************************************/
class LCD_ST7735S {
    void LCD_Reset(void);
    void LCD_WriteReg(uint8_t Reg);
    void LCD_WriteData_8Bit(uint8_t Data);
    void LCD_WriteData_16Bit(uint16_t Data);
    void LCD_WriteData_NLen16Bit(uint16_t Data, uint32_t DataLen);
    void LCD_InitReg(void);
    void LCD_SetGramScanWay(LCD_SCAN_DIR Scan_dir);
  public:
    void LCD_Init( LCD_SCAN_DIR Lcd_ScanDir );

    //LCD set cursor + windows + color
    void LCD_SetWindows( POINT Xstart, POINT Ystart, POINT Xend, POINT Yend );
    void LCD_SetCursor ( POINT Xpoint, POINT Ypoint );
    void LCD_SetColor( COLOR Color , POINT Xpoint, POINT Ypoint);
    void LCD_SetPointlColor ( POINT Xpoint, POINT Ypoint, COLOR Color );
    void LCD_SetArealColor ( POINT Xstart, POINT Ystart, POINT Xend, POINT Yend, COLOR  Color);
    void LCD_Clear(COLOR  Color);

    //Drawing
    void LCD_DrawPoint(POINT Xpoint, POINT Ypoint, COLOR Color, DOT_PIXEL Dot_Pixel, DOT_STYLE Dot_FillWay);
    void LCD_DrawLine ( POINT Xstart, POINT Ystart, POINT Xend, POINT Yend, COLOR Color, LINE_STYLE Line_Style, DOT_PIXEL Dot_Pixel);
    void LCD_DrawRectangle ( POINT Xstart, POINT Ystart, POINT Xend, POINT Yend, COLOR Color, DRAW_FILL Filled , DOT_PIXEL Dot_Pixel );
    void LCD_DrawCircle ( POINT X_Center, POINT Y_Center, LENGTH Radius, COLOR Color, DRAW_FILL Draw_Fill , DOT_PIXEL Dot_Pixel );

    //Display string
    void LCD_DisplayChar( POINT Xstart, POINT Ystart, const char Acsii_Char, sFONT* Font, COLOR Color_Background, COLOR Color_Foreground );
    void LCD_DisplayString (POINT Xstart, POINT Ystart, const char * pString, sFONT* Font, COLOR Color_Background, COLOR Color_Foreground );
    void LCD_DisplayNum(POINT Xpoint, POINT Ypoint, int32_t Nummber, sFONT* Font, COLOR Color_Background, COLOR Color_Foreground );
    void LCD_Show(void);
};
extern LCD_ST7735S LCD;
#endif
