#ifndef FP_HEADER
#define FP_HEADER
/* boolean type */
typedef int bool;
enum{false, true};


/*speed of person */
typedef int Speed;
enum{slow, med, fast};




struct movieGoer {
  int id;
  bool movie;
  bool snack;
  Speed speed;
  int (*payment) (Speed);
};
typedef struct movieGoer Patron;


/*payment functions to be used as parameters */
int chargeCard(Speed patronSpeed);
int cash( Speed patronSpeed);
int debit(Speed patronSpeed);
int cheque(Speed patronSpeed);


#endif
