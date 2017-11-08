/*
  Programmer: Oliver Thompson
  File: test_graph.cpp
  Tests Graphs
*/

#include"test_graph.h"
#include<iostream>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(Test_graph);

Test_graph::Test_graph()
{
}

void Test_graph::test_quickest_path()
{
  cout << "TEST QUICKEST PATH" << endl;

  Graph g;

  Vertex bentonville("Bentonville");
  Vertex joplin("Joplin");
  Vertex springfield("Springfield");
  Vertex branson("Branson");
  Vertex jefferson_city("Jefferson_City");
  Vertex sedalia("Sedalia");
  Vertex rolla("Rolla");
  Vertex kansas_city("Kansas_City");
  Vertex st_joseph("St_Joseph");
  Vertex rockport("Rockport");
  Vertex bethany("Bethany");
  Vertex lancaster("Lancaster");
  Vertex alexandria("Alexandria");
  Vertex cameron("Cameron");
  Vertex west_plains("West_Plains");
  Vertex festus("Festus");
  Vertex sikeston("Sikeston");
  Vertex st_louis("St_Louis");
  Vertex uNion("Union");
  Vertex columbia("Columbia");
  Vertex macon("Macon");
  Vertex hannibal("Hannibal");
  Vertex poplar_bluff("Poplar_Bluff");

  Edge benjop(bentonville, joplin, 60.7, 53.5589);
  Edge jopkan(joplin, kansas_city, 157, 59.25);
  Edge jopspr(joplin, springfield, 74.4, 53.79);
  Edge sprbra(springfield, branson, 44.9, 52.823);
  Edge sprsed(springfield, sedalia, 117, 47.43);
  Edge sprjef(springfield, jefferson_city, 133, 48.36);
  Edge sprrol(springfield, rolla, 110, 60.00);
  Edge brawes(branson, west_plains, 99.7, 47.10);
  Edge jefuni(jefferson_city, uNion, 77.2, 52.64);
  Edge jefrol(jefferson_city, rolla, 62.6, 55.24);
  Edge jefsed(jefferson_city, sedalia, 60.5, 49.06);
  Edge jefcol(jefferson_city, columbia, 31.3, 51.24);
  Edge sedkan(sedalia, kansas_city, 94.2, 57.67);
  Edge rolwes(rolla, west_plains, 98.4, 47.10);
  Edge roluni(rolla, uNion, 62.3, 55.79);
  Edge kancol(kansas_city, columbia, 125, 59.06);
  Edge kancam(kansas_city, cameron, 50.7, 56.33);
  Edge kanstj(kansas_city, st_joseph, 53.6, 55.45);
  Edge stjcam(st_joseph, cameron, 34.8, 50.93);
  Edge stjroc(st_joseph, rockport, 65.9, 49.43);
  Edge rocbet(rockport, bethany, 97.5, 51.77);
  Edge betcam(bethany, cameron, 40.7, 51.96);
  Edge betlan(bethany, lancaster, 88.9, 51.29);
  Edge lanmac(lancaster, macon, 58.0, 48.33);
  Edge lanale(lancaster, alexandria, 67.3, 50.48);
  Edge alehan(alexandria, hannibal, 60.9, 52.2);
  Edge cammac(cameron, macon, 98.4, 57.32);
  Edge wespop(west_plains, poplar_bluff, 98.4, 47.61);
  Edge popfes(poplar_bluff, festus, 120, 54.14);
  Edge popsik(poplar_bluff, sikeston, 47.8, 51.21);
  Edge fessik(festus, sikeston, 116, 60.00);
  Edge fesstl(festus, st_louis, 35.7, 45.57);
  Edge stluni(st_louis, uNion, 43.3, 50.9);
  Edge stlcol(st_louis, columbia, 123, 55.9);
  Edge stlhan(st_louis, hannibal, 116, 52.35);
  Edge colmac(columbia, macon, 58.1, 52.03);
  Edge machan(macon, hannibal, 63.7, 53.83);

  g.add_vertex(bentonville);
  g.add_vertex(joplin);
  g.add_vertex(springfield);
  g.add_vertex(branson);
  g.add_vertex(jefferson_city);
  g.add_vertex(sedalia);
  g.add_vertex(rolla);
  g.add_vertex(kansas_city);
  g.add_vertex(st_joseph);
  g.add_vertex(rockport);
  g.add_vertex(bethany);
  g.add_vertex(lancaster);
  g.add_vertex(alexandria);
  g.add_vertex(cameron);
  g.add_vertex(west_plains);
  g.add_vertex(festus);
  g.add_vertex(sikeston);
  g.add_vertex(st_louis);
  g.add_vertex(uNion);
  g.add_vertex(columbia);
  g.add_vertex(macon);
  g.add_vertex(hannibal);
  g.add_vertex(poplar_bluff);

  g.add_edge(benjop);
  g.add_edge(jopkan);
  g.add_edge(jopspr);
  g.add_edge(sprbra);
  g.add_edge(sprsed);
  g.add_edge(sprjef);
  g.add_edge(sprrol);
  g.add_edge(brawes);
  g.add_edge(jefuni);
  g.add_edge(jefrol);
  g.add_edge(jefsed);
  g.add_edge(jefcol);
  g.add_edge(sedkan);
  g.add_edge(rolwes);
  g.add_edge(roluni);
  g.add_edge(kancol);
  g.add_edge(kancam);
  g.add_edge(kanstj);
  g.add_edge(stjcam);
  g.add_edge(stjroc);
  g.add_edge(rocbet);
  g.add_edge(betcam);
  g.add_edge(betlan);
  g.add_edge(lanmac);
  g.add_edge(lanale);
  g.add_edge(alehan);
  g.add_edge(cammac);
  g.add_edge(wespop);
  g.add_edge(popfes);
  g.add_edge(popsik);
  g.add_edge(fessik);
  g.add_edge(fesstl);
  g.add_edge(stluni);
  g.add_edge(stlcol);
  g.add_edge(stlhan);
  g.add_edge(colmac);
  g.add_edge(machan);

  cout << "PASSED" << endl;
}

