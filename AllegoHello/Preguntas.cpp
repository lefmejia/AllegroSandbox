#include "Preguntas.h"

Preguntas::Preguntas() {
	bancoPreguntas[0][0] = "Uno de los siguientes personajes fue \nel encargado de pintar la capilla Sixtina: \nA) Miguel �ngel. \nB) Donatello. \nC) Leonardo Da Vinci. \nD) Francis Bacon";
	bancoPreguntas[0][1] = "Genio del renacimiento que esculpi� \nel Mois�s, el David y la Piet�: \nA) Miguel �ngel Buonarroti. \nB) Leonardo Da Vinci. \nC) Rafael Sanzio. \nD) Galileo Galilei";
	bancoPreguntas[0][2] = "Durante el renacimiento el estilo \nart�stico que impregn� el arte, la filosof�a, la pintura escritura fue el: \nA) El G�tico. \nB) El barroco. \nC) el clasicismo. \nD) Romanticismo";
	bancoPreguntas[0][3] = "Durante el renacimiento surge una \nnueva visi�n del hombre, que se vio reflejada en el arte, en la pol�tica y en las ciencias sociales y humanas, a lo que se denomina: \nA) Antropocentrismo. \nB) Humanismo. \nC) Paradigma antropol�gico. \nD) Teocentrismo.";
	bancoPreguntas[0][4] = "Cuatro genios del renacimiento (Leonardo, \nDonatello, Rafael y Michelangelo) han sido llevados a la pantalla en los comics de : \nA) Las tortugas ninjas. \nB) Los caballeros del Zodiaco. \nC) Los cuatro fant�sticos. \nD) Los antagonistas de Attack Titan";
	
	bancoPreguntas[1][0] = "Durante el renacimiento, el modelo de gobierno es uno de los siguientes: \nA) Monarqu�a absoluta. \nB) Tiran�a republicana. \nC) Democracia participativa. \nD) Liberalismo pol�tico.";
	bancoPreguntas[1][1] = "De los siguientes acontecimientos, selecciones el que inicia el per�odo moderno: \nA) Toma de Constantinopla. \nB) Tratado de paz de westfalia. \nC) Toma de la Bastilla. \nD) La ruta de la seda.";
	bancoPreguntas[1][2] = "Durante el siglo XV, la sociedad se estratifica en tres estamentos definidos: \nA) Clase media, baja y alta. \nB) nobleza, clero y estado llano. \nC) Artesanos, guardianes y gobernantes";
	bancoPreguntas[1][3] = "Aparece el realismo pol�tico, que se basaba en un orden establecido, explicaci�n de un sistema y recomendaciones de como gobernar: \nA) Tom�s Moro. \nB) Jean Bod�n. \nC) Nicolas Maquiavelo. \nD) Erasmo de Rotterdam.";
	bancoPreguntas[1][4] = "Terminada la edad media, en el contexto de la pol�tica resulta que: \nA) La Iglesia resalta su poder. \nB) La Iglesia pierde el papel rector en la pol�tica. \nC) La Iglesia evang�lica se posiciona en la pol�tica.";
	
	bancoPreguntas[2][0] = "Entre los siguientes renacentistas seleccione, uno de los precursores fil�sofo-cient�fico del heliocentrismo (teor�a que afirma que el sol es el centro del universo): \nA) Tomas Moro. \nB) Galileo. \nC) Plat�n.";
	bancoPreguntas[2][1] = "El m�todo cient�fico se introduce por el inter�s de tres fil�sofos. Entre los siguientes uno de los mencionados no es precursor del m�todo cient�fico: \nA) Francis Bacon. \nB) Galileo Galilei. \nC)Nicolas Maquiavelo. \nD) Ren� Descartes";
	bancoPreguntas[2][2] = "Es uno de los precursores del pensamiento Moderno: \nA) Isaac Newton. \nB) Ren� Descartes. \nC) Erasmo de Roterdam";
	bancoPreguntas[2][3] = "De los siguientes fil�sofos niega el geocentrismo (teor�a que afirma que el centro de nuestro sistema solar es la tierra): \nA) Arist�teles. \nB) Nicol�s Cop�rnico. \nC) Tom�s de Aquino";
	bancoPreguntas[2][4] = "Uno de los inventos que suscit� un conocimiento ilimitado, fue el de Gutenberg: \nA) El astrolabio. \nB) La imprenta. \nC) La Nao y la Carabela. \nD) El Telescopio";
	
	bancoPreguntas[3][0] = "Despues del feudalismo medieval acudimos al surgimiento de una nueva clase social conocida como la: \nA) La monarqu�a. \nB) El mercantilismo. \nC) La burgues�a. \nD) El proletariado";
	bancoPreguntas[3][1] = "El renacimiento supone una �poca de absolutismo y nacionalismos, como el nacimiento de fuertes monarqu�as europeas centralizadas como: \nA) Grecia. \nB) Inglaterra. \nC) Yugoslavia. \nD) Egipto";
	bancoPreguntas[3][2] = "Antes de la consolidaci�n del estado moderno, Italia estuvo divida en peque�as ciudades-estado normalmente enfrentadas entre si, como es el caso de: \nA) Florencia-Napoli. \nB) �msterdam-Cracovia. \nC) Reims-Colonia. \nD) Mil�n-Lourdes.";
	bancoPreguntas[3][3] = "La toma de Constantinopla supone un bloqueo comercial entre Europa y Asia (la ruta de la seda) y ocurri� en lo que hoy es actualmente: \nA) Eslovaquia. \nB) Estambul en Turqu�a. \nC) Mesopotamia";
	bancoPreguntas[3][4] = "Resurge el inter�s por Grecia y Roma, junto al declive del sistema feudal, el crecimiento del comercio e innovaciones entre las que mencionamos: \nA) La imprenta y la br�jula. \nB) La rueda y la escritura \nC) Las m�quinas de vapor y la producci�n en masa,";

	respuesta[0][0] = 0;
	respuesta[0][1] = 0;
	respuesta[0][2] = 1;
	respuesta[0][3] = 1;
	respuesta[0][4] = 0;
	
	respuesta[1][0] = 0;
	respuesta[1][1] = 1;
	respuesta[1][2] = 1;
	respuesta[1][3] = 2;
	respuesta[1][4] = 1;
	
	respuesta[2][0] = 1;
	respuesta[2][1] = 2;
	respuesta[2][2] = 1;
	respuesta[2][3] = 1;
	respuesta[2][4] = 1;
	
	respuesta[3][0] = 2;
	respuesta[3][1] = 1;
	respuesta[3][2] = 0;
	respuesta[3][3] = 1;
	respuesta[3][4] = 0;

}

string Preguntas::escogerPregunta(int cat, int pos) {
	return bancoPreguntas[cat][pos];
}

int Preguntas::escogerRespuesta(int cat, int pos) {
	return respuesta[cat][pos];
}