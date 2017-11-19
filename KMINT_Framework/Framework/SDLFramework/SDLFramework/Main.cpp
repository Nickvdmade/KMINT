#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
#include "Cow.h"
#include "Rabbit.h"

Graph FillGraph() 
{
	Graph graph;
	const int WEIGHT_NORMAL = 1;
	const int WEIGHT_WATER = 2;
	const int WEIGHT_LANE = 3;
	auto vertex1 = new Vertex(12, 564);
	graph.addVertex(vertex1);
	auto vertex103 = new Vertex(105, 548);
	graph.addVertex(vertex103);
	auto vertex104 = new Vertex(37, 540);
	graph.addVertex(vertex104);
	auto vertex105 = new Vertex(31, 470);
	graph.addVertex(vertex105);
	auto vertex107 = new Vertex(109, 488);
	graph.addVertex(vertex107);
	auto vertex108 = new Vertex(60, 420);
	graph.addVertex(vertex108);
	auto vertex109 = new Vertex(24, 424);
	graph.addVertex(vertex109);
	auto vertex110 = new Vertex(121, 417);
	graph.addVertex(vertex110);
	auto vertex111 = new Vertex(153, 456);
	graph.addVertex(vertex111);
	auto vertex112 = new Vertex(150, 506);
	graph.addVertex(vertex112);
	auto vertex113 = new Vertex(151, 550);
	graph.addVertex(vertex113);
	auto vertex114 = new Vertex(205, 528);
	graph.addVertex(vertex114);
	auto vertex115 = new Vertex(44, 376);
	graph.addVertex(vertex115);
	auto vertex116 = new Vertex(172, 400);
	graph.addVertex(vertex116);
	auto vertex117 = new Vertex(79, 466);
	graph.addVertex(vertex117);
	auto vertex118 = new Vertex(105, 370);
	graph.addVertex(vertex118);
	auto vertex119 = new Vertex(104, 291);
	graph.addVertex(vertex119);
	auto vertex120 = new Vertex(120, 258);
	graph.addVertex(vertex120);
	auto vertex121 = new Vertex(90, 244);
	graph.addVertex(vertex121);
	auto vertex122 = new Vertex(98, 212);
	graph.addVertex(vertex122);
	auto vertex123 = new Vertex(151, 268);
	graph.addVertex(vertex123);
	auto vertex124 = new Vertex(138, 226);
	graph.addVertex(vertex124);
	auto vertex125 = new Vertex(112, 186);
	graph.addVertex(vertex125);
	auto vertex126 = new Vertex(164, 200);
	graph.addVertex(vertex126);
	auto vertex127 = new Vertex(195, 171);
	graph.addVertex(vertex127);
	auto vertex128 = new Vertex(136, 144);
	graph.addVertex(vertex128);
	auto vertex129 = new Vertex(164, 135);
	graph.addVertex(vertex129);
	auto vertex130 = new Vertex(166, 98);
	graph.addVertex(vertex130);
	auto vertex131 = new Vertex(141, 58);
	graph.addVertex(vertex131);
	auto vertex132 = new Vertex(90, 96);
	graph.addVertex(vertex132);
	auto vertex133 = new Vertex(54, 156);
	graph.addVertex(vertex133);
	auto vertex134 = new Vertex(55, 211);
	graph.addVertex(vertex134);
	auto vertex135 = new Vertex(57, 268);
	graph.addVertex(vertex135);
	auto vertex136 = new Vertex(180, 331);
	graph.addVertex(vertex136);
	auto vertex137 = new Vertex(212, 354);
	graph.addVertex(vertex137);
	auto vertex138 = new Vertex(138, 332);
	graph.addVertex(vertex138);
	auto vertex139 = new Vertex(129, 294);
	graph.addVertex(vertex139);
	auto vertex140 = new Vertex(176, 292);
	graph.addVertex(vertex140);
	auto vertex141 = new Vertex(188, 267);
	graph.addVertex(vertex141);
	auto vertex142 = new Vertex(181, 249);
	graph.addVertex(vertex142);
	auto vertex143 = new Vertex(213, 223);
	graph.addVertex(vertex143);
	auto vertex144 = new Vertex(291, 283);
	graph.addVertex(vertex144);
	auto vertex145 = new Vertex(259, 313);
	graph.addVertex(vertex145);
	auto vertex146 = new Vertex(325, 357);
	graph.addVertex(vertex146);
	auto vertex147 = new Vertex(242, 379);
	graph.addVertex(vertex147);
	auto vertex148 = new Vertex(231, 428);
	graph.addVertex(vertex148);
	auto vertex149 = new Vertex(195, 439);
	graph.addVertex(vertex149);
	auto vertex150 = new Vertex(236, 528);
	graph.addVertex(vertex150);
	auto vertex151 = new Vertex(252, 469);
	graph.addVertex(vertex151);
	auto vertex152 = new Vertex(285, 469);
	graph.addVertex(vertex152);
	auto vertex153 = new Vertex(292, 450);
	graph.addVertex(vertex153);
	auto vertex154 = new Vertex(303, 415);
	graph.addVertex(vertex154);
	auto vertex155 = new Vertex(268, 413);
	graph.addVertex(vertex155);
	auto vertex156 = new Vertex(270, 384);
	graph.addVertex(vertex156);
	auto vertex157 = new Vertex(345, 387);
	graph.addVertex(vertex157);
	auto vertex158 = new Vertex(349, 430);
	graph.addVertex(vertex158);
	auto vertex159 = new Vertex(400, 452);
	graph.addVertex(vertex159);
	auto vertex160 = new Vertex(313, 488);
	graph.addVertex(vertex160);
	auto vertex161 = new Vertex(308, 528);
	graph.addVertex(vertex161);
	auto vertex162 = new Vertex(374, 472);
	graph.addVertex(vertex162);
	auto vertex163 = new Vertex(423, 481);
	graph.addVertex(vertex163);
	auto vertex164 = new Vertex(434, 519);
	graph.addVertex(vertex164);
	auto vertex165 = new Vertex(493, 480);
	graph.addVertex(vertex165);
	auto vertex166 = new Vertex(529, 427);
	graph.addVertex(vertex166);
	auto vertex167 = new Vertex(526, 366);
	graph.addVertex(vertex167);
	auto vertex168 = new Vertex(491, 367);
	graph.addVertex(vertex168);
	auto vertex169 = new Vertex(478, 386);
	graph.addVertex(vertex169);
	auto vertex170 = new Vertex(452, 340);
	graph.addVertex(vertex170);
	auto vertex171 = new Vertex(417, 369);
	graph.addVertex(vertex171);
	auto vertex172 = new Vertex(390, 404);
	graph.addVertex(vertex172);
	auto vertex184 = new Vertex(171, 481);
	graph.addVertex(vertex184);
	auto vertex200 = new Vertex(84, 402);
	graph.addVertex(vertex200);
	auto vertex231 = new Vertex(214, 55);
	graph.addVertex(vertex231);
	auto vertex232 = new Vertex(265, 56);
	graph.addVertex(vertex232);
	auto vertex233 = new Vertex(336, 54);
	graph.addVertex(vertex233);
	auto vertex234 = new Vertex(369, 54);
	graph.addVertex(vertex234);
	auto vertex235 = new Vertex(376, 135);
	graph.addVertex(vertex235);
	auto vertex236 = new Vertex(404, 171);
	graph.addVertex(vertex236);
	auto vertex237 = new Vertex(331, 190);
	graph.addVertex(vertex237);
	auto vertex238 = new Vertex(369, 210);
	graph.addVertex(vertex238);
	auto vertex239 = new Vertex(343, 145);
	graph.addVertex(vertex239);
	auto vertex240 = new Vertex(322, 103);
	graph.addVertex(vertex240);
	auto vertex241 = new Vertex(294, 104);
	graph.addVertex(vertex241);
	auto vertex242 = new Vertex(285, 134);
	graph.addVertex(vertex242);
	auto vertex243 = new Vertex(278, 152);
	graph.addVertex(vertex243);
	auto vertex244 = new Vertex(231, 142);
	graph.addVertex(vertex244);
	auto vertex245 = new Vertex(187, 127);
	graph.addVertex(vertex245);
	auto vertex248 = new Vertex(236, 183);
	graph.addVertex(vertex248);
	auto vertex249 = new Vertex(253, 204);
	graph.addVertex(vertex249);
	auto vertex255 = new Vertex(268, 84);
	graph.addVertex(vertex255);
	auto vertex262 = new Vertex(220, 102);
	graph.addVertex(vertex262);
	auto vertex266 = new Vertex(340, 85);
	graph.addVertex(vertex266);
	auto vertex277 = new Vertex(313, 259);
	graph.addVertex(vertex277);
	auto vertex280 = new Vertex(297, 184);
	graph.addVertex(vertex280);
	auto vertex281 = new Vertex(313, 176);
	graph.addVertex(vertex281);
	auto vertex282 = new Vertex(307, 206);
	graph.addVertex(vertex282);
	auto vertex287 = new Vertex(309, 147);
	graph.addVertex(vertex287);
	auto vertex304 = new Vertex(82, 201);
	graph.addVertex(vertex304);
	auto vertex309 = new Vertex(268, 358);
	graph.addVertex(vertex309);
	auto vertex311 = new Vertex(312, 375);
	graph.addVertex(vertex311);
	auto vertex330 = new Vertex(355, 339);
	graph.addVertex(vertex330);
	auto vertex343 = new Vertex(438, 313);
	graph.addVertex(vertex343);
	auto vertex345 = new Vertex(490, 324);
	graph.addVertex(vertex345);
	auto vertex348 = new Vertex(462, 303);
	graph.addVertex(vertex348);
	auto vertex351 = new Vertex(468, 282);
	graph.addVertex(vertex351);
	auto vertex352 = new Vertex(394, 232);
	graph.addVertex(vertex352);
	auto vertex353 = new Vertex(429, 229);
	graph.addVertex(vertex353);
	auto vertex354 = new Vertex(400, 272);
	graph.addVertex(vertex354);
	auto vertex355 = new Vertex(397, 309);
	graph.addVertex(vertex355);
	auto vertex356 = new Vertex(386, 341);
	graph.addVertex(vertex356);
	auto vertex360 = new Vertex(384, 297);
	graph.addVertex(vertex360);
	auto vertex364 = new Vertex(447, 273);
	graph.addVertex(vertex364);
	auto vertex371 = new Vertex(524, 298);
	graph.addVertex(vertex371);
	auto vertex372 = new Vertex(522, 199);
	graph.addVertex(vertex372);
	auto vertex373 = new Vertex(468, 202);
	graph.addVertex(vertex373);
	auto vertex374 = new Vertex(465, 228);
	graph.addVertex(vertex374);
	auto vertex375 = new Vertex(475, 248);
	graph.addVertex(vertex375);
	auto vertex383 = new Vertex(453, 145);
	graph.addVertex(vertex383);
	auto vertex384 = new Vertex(418, 118);
	graph.addVertex(vertex384);
	auto vertex385 = new Vertex(417, 31);
	graph.addVertex(vertex385);
	auto vertex386 = new Vertex(420, 67);
	graph.addVertex(vertex386);
	auto vertex387 = new Vertex(398, 94);
	graph.addVertex(vertex387);
	auto vertex388 = new Vertex(451, 88);
	graph.addVertex(vertex388);
	auto vertex389 = new Vertex(481, 110);
	graph.addVertex(vertex389);
	auto vertex390 = new Vertex(476, 168);
	graph.addVertex(vertex390);
	auto vertex391 = new Vertex(500, 151);
	graph.addVertex(vertex391);
	auto vertex392 = new Vertex(546, 146);
	graph.addVertex(vertex392);
	auto vertex393 = new Vertex(541, 103);
	graph.addVertex(vertex393);
	auto vertex394 = new Vertex(531, 45);
	graph.addVertex(vertex394);
	auto vertex395 = new Vertex(550, 24);
	graph.addVertex(vertex395);
	auto vertex396 = new Vertex(470, 42);
	graph.addVertex(vertex396);
	auto vertex432 = new Vertex(440, 424);
	graph.addVertex(vertex432);
	graph.addEdge(new Edge(vertex1, vertex104, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex103, vertex107, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex117, vertex107, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex117, vertex105, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex105, vertex104, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex104, vertex103, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex103, vertex113, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex113, vertex112, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex112, vertex107, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex107, vertex111, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex111, vertex184, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex184, vertex112, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex112, vertex114, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex184, vertex114, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex114, vertex113, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex117, vertex110, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex108, vertex117, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex110, vertex116, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex116, vertex111, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex110, vertex111, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex105, vertex109, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex109, vertex108, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex108, vertex115, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex115, vertex109, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex108, vertex200, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex200, vertex110, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex115, vertex200, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex114, vertex149, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex149, vertex116, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex116, vertex118, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex118, vertex115, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex114, vertex150, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex150, vertex151, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex151, vertex148, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex148, vertex149, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex148, vertex147, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex147, vertex137, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex137, vertex116, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex137, vertex136, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex136, vertex140, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex140, vertex141, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex141, vertex145, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex145, vertex137, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex136, vertex138, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex138, vertex139, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex139, vertex140, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex139, vertex119, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex119, vertex118, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex119, vertex135, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex135, vertex115, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex135, vertex134, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex134, vertex133, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex133, vertex132, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex132, vertex131, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex245, vertex244, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex244, vertex242, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex244, vertex248, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex248, vertex249, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex242, vertex243, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex242, vertex241, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex241, vertex240, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex241, vertex255, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex255, vertex232, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex232, vertex231, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex231, vertex131, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex131, vertex130, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex130, vertex262, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex262, vertex255, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex233, vertex232, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex240, vertex266, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex266, vertex233, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex233, vertex234, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex234, vertex235, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex235, vertex239, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex239, vertex240, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex239, vertex237, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex237, vertex238, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex238, vertex236, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex236, vertex235, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex277, vertex238, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex277, vertex249, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex282, vertex280, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex280, vertex249, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex280, vertex281, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex287, vertex281, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex287, vertex242, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex127, vertex126, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex126, vertex124, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex126, vertex128, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex128, vertex132, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex143, vertex126, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex143, vertex144, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex144, vertex277, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex144, vertex145, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex143, vertex142, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex142, vertex141, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex119, vertex120, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex120, vertex123, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex120, vertex121, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex121, vertex122, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex134, vertex304, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex124, vertex125, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex123, vertex124, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex146, vertex145, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex309, vertex156, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex146, vertex311, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex311, vertex156, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex156, vertex155, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex155, vertex153, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex153, vertex154, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex153, vertex152, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex152, vertex151, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex152, vertex160, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex160, vertex161, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex161, vertex150, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex161, vertex164, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex164, vertex163, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex163, vertex162, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex162, vertex160, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex159, vertex158, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex158, vertex153, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex158, vertex157, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex157, vertex311, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex330, vertex146, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex330, vertex144, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex171, vertex172, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex165, vertex164, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex165, vertex166, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex166, vertex167, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex167, vertex168, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex168, vertex169, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex169, vertex170, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex171, vertex170, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex343, vertex170, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex345, vertex168, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex348, vertex345, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex348, vertex343, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex330, vertex356, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex356, vertex171, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex356, vertex355, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex355, vertex360, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex360, vertex277, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex360, vertex354, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex364, vertex354, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex354, vertex352, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex352, vertex353, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex353, vertex364, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex364, vertex351, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex348, vertex351, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex375, vertex351, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex375, vertex374, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex374, vertex373, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex373, vertex372, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex372, vertex371, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex371, vertex167, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex373, vertex236, WEIGHT_LANE));
	graph.addEdge(new Edge(vertex395, vertex394, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex394, vertex396, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex396, vertex385, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex385, vertex386, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex385, vertex234, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex234, vertex386, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex386, vertex387, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex387, vertex384, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex384, vertex388, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex388, vertex386, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex388, vertex396, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex388, vertex389, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex389, vertex383, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex384, vertex383, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex383, vertex236, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex236, vertex384, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex383, vertex390, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex390, vertex391, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex391, vertex389, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex389, vertex393, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex393, vertex392, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex392, vertex391, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex391, vertex372, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex372, vertex392, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex393, vertex394, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex352, vertex238, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex129, vertex128, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex129, vertex130, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex245, vertex129, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex245, vertex130, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex249, vertex143, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex122, vertex304, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex125, vertex304, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex159, vertex163, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex432, vertex171, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex432, vertex159, WEIGHT_NORMAL));
	graph.addEdge(new Edge(vertex432, vertex165, WEIGHT_WATER));
	graph.addEdge(new Edge(vertex351, vertex371, WEIGHT_NORMAL));
	return graph;
}

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	
	//Graph
	auto graph = FillGraph();

	//cow & rabbit
	auto cow = new Cow(application);
	auto rabbit = new Rabbit(application);
	int xCow = 12;
	int yCow = 564;
	int xRabbit = 440;
	int yRabbit = 424;


	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
				case SDLK_SPACE: // move cow
					

					xCow += 10;
					yCow -= 10;
					break;
				default:
					break;
				}
			}
		}
		

		//Week1	
		graph.DrawGraph(application);
		cow->Draw(xCow, yCow);
		rabbit->Draw(xRabbit, yRabbit);
		
		
		
		
		
		// For the background
		application->SetColor(Color(220, 220, 220, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}