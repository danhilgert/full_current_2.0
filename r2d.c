#include "r2d.h"

void init_R2D_spi(void) {
	// MOSI	--	PC12
	// MISO --	PC11
	// SCL	--	PC10
	// CS	--	always held low
	// WR	-- ??
	// APB1 Freq = 42MHz (??)

	SPI_InitTypeDef spi_init_t;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, ENABLE);	// 42Mhz(??)  do this first

    GPIO_InitTypeDef gpio_init_t;

	//SCK, MOSI, MISO
	GPIO_PinAFConfig(GPIOC, R2D_SDO, GPIO_AF_SPI3);
	GPIO_PinAFConfig(GPIOC, R2D_SDI, GPIO_AF_SPI3);
	GPIO_PinAFConfig(GPIOC, R2D_SCK, GPIO_AF_SPI3);

	GPIO_StructInit(&gpio_init_t);	// clear structure

	// spi3 pins
	gpio_init_t.GPIO_Pin = GPIO_Pin_11| GPIO_Pin_12 | GPIO_Pin_10;
	gpio_init_t.GPIO_Mode = GPIO_Mode_AF;
	gpio_init_t.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_Init(GPIOC, &gpio_init_t);

	// A0 A1 - PORTB
	GPIO_StructInit(&gpio_init_t);		// clear structure
	gpio_init_t.GPIO_Pin = A0 | A1;
	gpio_init_t.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(GPIOB, &gpio_init_t);

	// DOS - PORTB
	gpio_init_t.GPIO_Pin = DOS;
	gpio_init_t.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOB, &gpio_init_t);

	// LOT NWR - PORT D
	gpio_init_t.GPIO_Pin = LOT | NWR;
	gpio_init_t.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOD, &gpio_init_t);

	// NReset NSample - PORT D
	gpio_init_t.GPIO_Pin = NReset | NSample;
	gpio_init_t.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(GPIOD, &gpio_init_t);

	// RES0 RES1- PORTE
	gpio_init_t.GPIO_Pin = RES0 | RES1;
	gpio_init_t.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(GPIOE, &gpio_init_t);


	//GPIO_SetBits(GPIOB, LTC6804_EN);		// enable high
	//GPIO_ResetBits(GPIOB, LTC6804_CS);		// CS high (active low)


	SPI_StructInit(&spi_init_t);		// set struct to default

	spi_init_t.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	spi_init_t.SPI_Mode = SPI_Mode_Master;
	spi_init_t.SPI_DataSize = SPI_DataSize_8b;
	spi_init_t.SPI_CPOL = SPI_CPOL_High;	// NEED TO KNOW THESE
	spi_init_t.SPI_CPHA = SPI_CPHA_2Edge;	// NEED TO KNOW THESE
	spi_init_t.SPI_NSS = SPI_NSS_Soft;
	spi_init_t.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32; // SCL = 1.53452MHz @ 32
	spi_init_t.SPI_FirstBit = SPI_FirstBit_MSB;
	//spi_init_t.SPI_CRCPolynomial =  ?????
	SPI_Init(SPI3, &spi_init_t);

	SPI_Cmd(SPI3, ENABLE);
}
