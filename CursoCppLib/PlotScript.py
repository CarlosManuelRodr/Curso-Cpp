# Encoding: utf-8
import matplotlib.pyplot as plotter
import sys
import csv

# Verifica que haya argumentos.
if len(sys.argv) > 1:
	fileName = sys.argv[1];

	# Intenta abrir el archivo.
	try:
		f = open(fileName, 'rb')
	except IOError:
		print("Error: No se puede abrir archivo")
		sys.exit(0)

	reader = csv.reader(f)

	xArray = []
	yArray = []

	# Extrae elementos del archivo.
	for row in reader:
		xArray.append(row[0])
		yArray.append(row[1])
			
	# Crea gráfica
	fig = plotter.figure() 
	fig.canvas.set_window_title('Grafica') 

	plotter.plot(xArray,yArray, 'b')
	plotter.xlabel('$x$');
	plotter.ylabel('$y$');
	plotter.title(u'Grafica');
	plotter.grid(True);
	plotter.axis('auto');
	plotter.show();
else:
	print("Debe especificar un archivo. Ejemplo: python PlotScript.py 'datos.csv'");
