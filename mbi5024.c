/************************************************************************/
/* ���ƣ�MBI5020/5024/5026��16λ����оƬ����
 * ������
 * ��д����Ӧ��
 * �޸ģ�2016-11-26
 * Ե�ɣ��滪5517*/
/************************************************************************/
#include "../main.h"
 /************************************************************************/
/* ���ܣ�MBI ��������
 * ������
 * �βΣ��������鿪ʼ��ַ(16bit)��оƬ������Ŀ(Ҳ�����鳤��)
 * ���أ���    */
/************************************************************************/

void mbi_out(u16 *buf,s8 cnt)
{
	u8 high,low;
	// MBI_OE_H;
	MBI_LE_L;
	for (s8 i=0; i<cnt; i++)
	{
		high = (u8)((*(buf+i)>>8));
		low = (u8)(*(buf+i));

		spi_master_transmit(high);
		spi_master_transmit(low);
	 }
	 asm("NOP");
	 MBI_LE_H;
	 asm("NOP");
	 MBI_LE_L;
	 MBI_OE_L;
 }
 #if 0
 void mbi_out(u16 tmp_gui,s8 cnt)
 {
	u8 high,low;
	MBI_LE_L;
//	MBI_OE_H;
	delay_us();
	for (s8 i=0; i<cnt; i++)
	{
		//low = (u8)(tmp_gui+i);
	//	high = (u8)((tmp_gui+i)>>8);
		low = 0xFF;
		high = 0x00;
		//spi_master_transmit(high);
		//spi_master_transmit(low);

		for(s8 j=0; j<16; j++)
		{
			
		}
	}
	MBI_LE_H;
	//delay_us();
	//MBI_LE_L;
	//delay_us();
	MBI_OE_L;
 }
 #endif