

union u_tag{
	int ival;
	float fval;
	char *sval;
}u;
//union 的存储空间是最大类型所需的空间


//使用union的时候 只能把他始终对待成同一种类型

if(utype == INT)
	printf("%d\n",u.ival);
if(utype == FLOAT)
	printf("%f\n",u.fval);
if(utype == STRING)
	printf("%s\n",u.sval);
else 
	printf("bad type %d in utype\n",utype);



#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04

enum {KEYWORD = 01,EXTERNAL = 02,STATIC = 04};

flags |= EXTERNAL | STATIC;
//turns on the EXTERNAL and STATIC bit in flags,while
flags &= ~(EXTERNAL | STATIC);
//turns them off

if((flags & (EXTERNAL | STATIC)) == 0)
//is true if both bits are off


//more naturally
//bitfield
struct{
	unsigned int is_keyword : 1;
	unsigned int is_extern : 1;
	unsigned int is_extern : 1;
}flags;
//This defines a variable table called flags that contains three 1 - bit fields.
//The number following the colon represents the field width in bits.
//The fields are declared unsigned intto ensure that they are unsigned quantities.

flags.is_extern = flags.is_static = 1;
flags.is_extern = flags.is_static = 0;

if(flags.is_extern == 0 && flags.is_static == 0)


