# Trabajo Práctico 2 - Detectar vulnerabilidades con Fuzzing

**Materia:** Sistemas Operativos y Redes II.
**Grupo:** 2.
**Integrantes:** Ezequiel Ravignani, Carlos Caballero, Cristian Yoel Garay, Juan Farias y Pablo Igei Nakagawa.

## Archivos del proyecto
- **insert.c** - Programa que inserta una palabra en una cadena base en la pocision dada.
- **insert** -  Programa compilado.
- **input.txt** - Parametros originales para pasar a insert.
- **last_input.txt** - Aqui se guarda los ultimos parametros enviados.
- **fuzzing.sh** - Lee el input.txt, lo pasa por radamsa y llama a insert en un bucle.

## Compilación y ejecución
**Dentro de la terminal de linux:**
- Descargar radamsa.
- Colocar los parametros en input.txt respetando el formato (o dejarlo como esta).
- Ejecutar el bash con ./fuzzing.sh
- Si hay un error revisar last_input.txt
