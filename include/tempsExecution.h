typedef void (*algotithme)(float *);
typedef void (*algotithmeAvecTaille)(float *, int);
float tempsExecution(algotithme fonctionTri,float * tableauATrier);
float tempsExecutionAvecTaille(algotithmeAvecTaille fonctionTri,float * tableauATrier, int taille);