/**********************************************
* Author	:	qiuguizhu
* Date		: 	2017/8/18
* Description	:	Test struct
***********************************************/

#include<stdio.h>

struct 

/*function ptr
struct mtd_info
{
	int (*read_oob) (struct mtd_info *mtd, int from,
			 struct mtd_oob_ops *ops);
	int (*write_oob) (struct mtd_info *mtd, int to,
			 struct mtd_oob_ops *ops);

}mtd_a;
struct mtd_oob_ops {
	unsigned int	mode;
	unsigned int	len;
	unsigned int	retlen;
	unsigned int	ooblen;
	unsigned int	oobretlen;
	unsigned int	ooboffs;
	unsigned int	*datbuf;
	unsigned int	*oobbuf;
}ops_a;

int mtd_read_oob(struct mtd_info *mtd, int from, struct mtd_oob_ops *ops)
{
	ops->retlen = ops->oobretlen = 0;
	if (!mtd->_read_oob)
		return -93;
	return mtd->_read_oob(mtd, from, ops);
}

int main()
{
	mtd_read_oob(ops_a, 3, &ops_a);	
}*/
