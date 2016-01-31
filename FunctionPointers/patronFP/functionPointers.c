#include <stdlib.h>
#include <stdio.h>
#include "fpheader.h"


int chargeCard(Speed patronSpeed){

  return (60*(3-patronSpeed));
}


int cash( Speed patronSpeed){

  return(120*(3-patronSpeed));

}

int debit(Speed patronSpeed){

  return(45*(3-patronSpeed));
}

int cheque(Speed patronSpeed){

  return(300*(3-patronSpeed));
}
