HEADERS += \
  agarre.h \
  agarre_quitanieves.h \
  asiento.h \
  bombilla.h \
  brazo.h \
  cabeza.h \
  cabeza_rellena.h \
  chasis.h \
  cilindro.h \
  coche.h \
  colors.h \
  basic_object3d.h \
  cono.h \
  cube.h \
  cuerpo.h \
  cuerpo_equipado.h \
  cuerpo_quitanieves.h \
  eje.h \
  eje_rueda.h \
  escaleras.h \
  esfera.h \
  excavadora.h \
  excavadora_quitanieves.h \
  file_ply_stl.h \
  grua.h \
  hierarchical.h \
  lighting.h \
  luces.h \
  luna.h \
  luna_parabrisas.h \
  mastil.h \
  material.h \
  matriz_ply.h \
  object3d.h \
  axis.h \
  pala.h \
  parabrisas.h \
  peldanios.h \
  ply.h \
  ply_perfil.h \
  puerta.h \
  puerta_ventanilla.h \
  quitanieves.h \
  respaldo.h \
  rev.h \
  rueda.h \
  sillon.h \
  sistema_escaleras.h \
  sistema_puertasventanilla.h \
  sistema_ruedas.h \
  tablero.h \
  tapa_izq.h \
  techo.h \
  tetrahedron.h \
  glwidget.h \
  ventanilla.h \
  viga.h \
  window.h

SOURCES += \
  agarre.cc \
  agarre_quitanieves.cc \
  asiento.cc \
  basic_object3d.cc \
  bombilla.cc \
  brazo.cc \
  cabeza.cc \
  cabeza_rellena.cc \
  chasis.cc \
  cilindro.cc \
  coche.cc \
  cono.cc \
  cube.cc \
  cuerpo.cc \
  cuerpo_equipado.cc \
  cuerpo_quitanieves.cc \
  eje.cc \
  eje_rueda.cc \
  escaleras.cc \
  esfera.cc \
  excavadora.cc \
  excavadora_quitanieves.cc \
  file_ply_stl.cc \
  grua.cc \
  hierarchical.cc \
  lighting.cc \
  luces.cc \
  luna.cc \
  luna_parabrisas.cc \
  mastil.cc \
  material.cc \
  matriz_ply.cc \
  object3d.cc \
  axis.cc \
  pala.cc \
  parabrisas.cc \
  peldanios.cc \
  ply.cc \
  ply_perfil.cc \
  puerta.cc \
  puerta_ventanilla.cc \
  quitanieves.cc \
  respaldo.cc \
  rev.cc \
  rueda.cc \
  sillon.cc \
  sistema_escaleras.cc \
  sistema_puertasventanilla.cc \
  sistema_ruedas.cc \
  tablero.cc \
  tapa_izq.cc \
  techo.cc \
  tetrahedron.cc \
  glwidget.cc \
  ventanilla.cc \
  viga.cc \
  window.cc \
  main.cc


INCLUDEPATH += "C:\Users\xaviv\Desktop\JAVIER\UNIVERSIDAD\CURSO 20.21\CURSO\1CUATRI\INFORMATICA GRAFICA\PRACTICAS\skeleton\GL"
LIBS += -lopengl32 -L"C:\Users\xaviv\Desktop\JAVIER\UNIVERSIDAD\glew-2.1.0\bin\Release\x64" -lglew32



CONFIG += c++11
QT += widgets
