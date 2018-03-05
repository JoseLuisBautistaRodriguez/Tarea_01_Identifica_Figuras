	//			||	Tarea_EDA_1	||
/**
 * Implentar un TDA para un paralelogramo el cual queda definido como:
 * por el numero de puntos y un arreglo de Puntos donde el orden define la conectividad
 * de los mismos.
 * Crear las funciones es_cuadrado, es_rectangulo, es_triangulo.
 * Hint: implemente el TDA para definir un Punto en 2D
 */
 
 /*	
 	Las funciones {es_cuadrado, es_rombo, es_rectangulo } = Declara_figura;	 el cual descarta 
 	el tipo de figura en función de la distancia de sus lados y la localización de los puntos.
 	
 	Hint - se ha restringido a 1 figura, se solicita al usuario su entrada en el do-while.
	 
*/

#include <stdio.h>
#include <math.h>
//#include <string.h>


struct Point
{
    /** X coordinate */
    float x; 
    
    /** Y coordinate */
    float y;
};

/**
 * Computes the euclidean distance between two points 
 */
float distance(Point p, Point q);

/**
 * Moves a point the desired delta (dx,dy)
 */
void move(Point *p, float dx, float dy);

/**
 * Computes the dot product between two points
 */ 
float dot_product(Point *p, Point *q);

/*
* Prints the point
 */
void print(float *p, float *q);

void DeclaraFigura( Point *P_figura );
 

// --------------------------------------------------------------------------
// --------------------------------------------------------------------------    


 struct Paralelogram {
	Point forma[4];
 } usuario;
//
// Paralelogram constructor(int _num_points, Point *_points);

// void is_triangle(paralelogram *p);
//
// void is_square(paralelogram *p);
//
// void is_rectangle(paralelogram *p);

  


// --------------------------------------------------------------------------
// --------------------------------  Main  ----------------------------------
// --------------------------------------------------------------------------  
int main()
{
    // the square
    Point s[4];
    s[0].x = 0; s[0].y = 0;
    s[1].x = 5; s[1].y = 0;
    s[2].x = 5; s[2].y = 5;
    s[3].x = 0; s[3].y = 5;

    printf("\n\t --- El cuadrado --- ");
    for(int i = 0; i < 4 ; i++){
    	printf("\n\t%c Valor en s x : %02.2f\tValor en s y : %02.2f  %c ", 219,  (s[i].x ) , (s[i].y), 219);
    	print( &(s[i]).x , &(s[i].y) );
	}
    
    // the rectangle
    Point r[4];
	r[0].x = 0;  r[0].y = 0;
    r[1].x = 10; r[1].y = 0;
    r[2].x = 10; r[2].y = 5;
    r[3].x = 0;  r[3].y = 5;
    
    //Point R[] = {r1, r2, r3, r4};

    printf("\n\n\t --- El rectangulo --- ");
    for(int i = 0; i < 4; i++)
    {
	    printf( "\n\t%c Valor en r x : %02.2f\tValor en r y : %02.2f  %c ", 219 , (r[i].x), (r[i].y), 219);
        print( &(r[i].x ) , &(r[i].y ));
	}
    // the diamod
    Point d[4];
    
    d[0].x = 0;  d[0].y = 0;
    d[1].x = 5;  d[1].y = 2.5;
    d[2].x = 0;  d[2].y = 5;
    d[3].x = -5; d[3].y = 2.5;

    printf("\n\n\t --- El rombo --- ");
    for(int i = 0; i < 4; i++)
    {
    	printf("\n\t%c Valor en r x : %03.2f\tValor en r y : %03.2f  %c ", 219 , (d[i].x), (d[i].y), 219 );
    	print(&d[i].x, &d[i].y );
	}
     
	 DeclaraFigura( s ); 
	 DeclaraFigura( r ); 
	 DeclaraFigura( d );   
	
	short referencia = 0;
	
	do{
		printf("\n\tIngresa las cordenadas de un paralelogramo (4 puntos)");
		printf("\n\t  Valor %i en x : ", (referencia+1));
		scanf("%f", &usuario.forma[referencia].x);
		fflush(stdin);
		printf("\n\t  Valor %i en y : ", (referencia+1));
		scanf("%f", &usuario.forma[referencia].y);
		fflush(stdin);
		referencia++;
	}while( referencia != 4 );
	
	DeclaraFigura( usuario.forma );
	
	system("pause");
  return 0;      
    
}

// --------------------------------------------------------------------------
float distance(Point a, Point b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// --------------------------------------------------------------------------

void move(Point *p, float dx, float dy)
{
    p->x += dx;
    p->y += dy;
}

// --------------------------------------------------------------------------
float dot_product(Point *p, Point *q)
{
    float x = p->x * q->x;
    float y = p->y * q->y;
    return x + y;
}

// --------------------------------------------------------------------------
void print( float *p, float *q )
{
    printf(" (%0.2f, %0.2f) %c", *p, *q, 219);
}

// --------------------------------------------------------------------------

	void DeclaraFigura(Point *P_figura )
	{
		float distancia[4];
		for(short i = 0; i < 4 ; i++ )
		{
			if ( i < 3 )
			{
				distancia[i] = distance(P_figura[i], P_figura[i+1] );	
			}else if( i == 3){
				distancia[i] = distance(P_figura[i], P_figura[0] );	
			}
			//printf("\n\tDistancia = %02.2f ", distancia[i]);
		}

		if ( distancia[0] != distancia[1] )
		{
			printf("\n\t\tEs un rectangulo.\n");
		}else if( P_figura[0].x != P_figura[1].x && P_figura[0].x != P_figura[3].x )
		{
			printf("\n\t\tEs un rombo.\n");
		}else{
			printf("\n\t\tEs un Cuadrado.\n");
		}
	}
	
/*
		||		Datos Generales del archivo:		||
	------------------------------------------------------------------------------------------
	Universidad Nacional Autónoma de México
	Facultad de Ingeniería
	1227 Estructura de Datos y Algoritmos 1
	Grupo: 09
	
	Tarea: 01
	 
	Autor: Bautista Rodríguez José Luis   N° 04
	Fecha de inicio: 05/03/2018
	------------------------------------------------------------------------------------------	||

*/
