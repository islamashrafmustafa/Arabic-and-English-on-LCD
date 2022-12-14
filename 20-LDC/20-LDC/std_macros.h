#define REGISTER_SIZE 8
#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=(~(1<<bit))
#define TOG_BIT(reg,bit) reg^=(1<<bit)
#define READ_BIT(reg,bit) reg&=((1<<bit)>>bit)
#define IS_SET_BIT(reg,bit) (reg&=(1<<bit))>>bit
#define IS_CLE_BIT(reg,bit) !(reg&=(1<<bit))>>bit)
#define ROR(reg,bit) reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROR(reg,bit) reg=(reg>>EGISTER_SIZE-num))|(reg<<(num))