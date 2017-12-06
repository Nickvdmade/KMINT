#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Astar.h"
#include <Windows.h>

Graph FillGraph() 
{
	Graph graph;
	const int WEIGHT_NORMAL = 1;
	const int WEIGHT_WATER = 2;
	const int WEIGHT_LANE = 3;
	auto vertex1 = new Vertex(12, 564);
	graph.AddVertex(vertex1);
	auto vertex103 = new Vertex(105, 548);
	graph.AddVertex(vertex103);
	auto vertex104 = new Vertex(37, 540);
	graph.AddVertex(vertex104);
	auto vertex105 = new Vertex(31, 470);
	graph.AddVertex(vertex105);
	auto vertex107 = new Vertex(109, 488);
	graph.AddVertex(vertex107);
	auto vertex108 = new Vertex(60, 420);
	graph.AddVertex(vertex108);
	auto vertex109 = new Vertex(24, 424);
	graph.AddVertex(vertex109);
	auto vertex110 = new Vertex(121, 417);
	graph.AddVertex(vertex110);
	auto vertex111 = new Vertex(153, 456);
	graph.AddVertex(vertex111);
	auto vertex112 = new Vertex(150, 506);
	graph.AddVertex(vertex112);
	auto vertex113 = new Vertex(151, 550);
	graph.AddVertex(vertex113);
	auto vertex114 = new Vertex(205, 528);
	graph.AddVertex(vertex114);
	auto vertex115 = new Vertex(44, 376);
	graph.AddVertex(vertex115);
	auto vertex116 = new Vertex(172, 400);
	graph.AddVertex(vertex116);
	auto vertex117 = new Vertex(79, 466);
	graph.AddVertex(vertex117);
	auto vertex118 = new Vertex(105, 370);
	graph.AddVertex(vertex118);
	auto vertex119 = new Vertex(104, 291);
	graph.AddVertex(vertex119);
	auto vertex120 = new Vertex(120, 258);
	graph.AddVertex(vertex120);
	auto vertex121 = new Vertex(90, 244);
	graph.AddVertex(vertex121);
	auto vertex122 = new Vertex(98, 212);
	graph.AddVertex(vertex122);
	auto vertex123 = new Vertex(151, 268);
	graph.AddVertex(vertex123);
	auto vertex124 = new Vertex(138, 226);
	graph.AddVertex(vertex124);
	auto vertex125 = new Vertex(112, 186);
	graph.AddVertex(vertex125);
	auto vertex126 = new Vertex(164, 200);
	graph.AddVertex(vertex126);
	auto vertex127 = new Vertex(195, 171);
	graph.AddVertex(vertex127);
	auto vertex128 = new Vertex(136, 144);
	graph.AddVertex(vertex128);
	auto vertex129 = new Vertex(164, 135);
	graph.AddVertex(vertex129);
	auto vertex130 = new Vertex(166, 98);
	graph.AddVertex(vertex130);
	auto vertex131 = new Vertex(141, 58);
	graph.AddVertex(vertex131);
	auto vertex132 = new Vertex(90, 96);
	graph.AddVertex(vertex132);
	auto vertex133 = new Vertex(54, 156);
	graph.AddVertex(vertex133);
	auto vertex134 = new Vertex(55, 211);
	graph.AddVertex(vertex134);
	auto vertex135 = new Vertex(57, 268);
	graph.AddVertex(vertex135);
	auto vertex136 = new Vertex(180, 331);
	graph.AddVertex(vertex136);
	auto vertex137 = new Vertex(212, 354);
	graph.AddVertex(vertex137);
	auto vertex138 = new Vertex(138, 332);
	graph.AddVertex(vertex138);
	auto vertex139 = new Vertex(129, 294);
	graph.AddVertex(vertex139);
	auto vertex140 = new Vertex(176, 292);
	graph.AddVertex(vertex140);
	auto vertex141 = new Vertex(188, 267);
	graph.AddVertex(vertex141);
	auto vertex142 = new Vertex(181, 249);
	graph.AddVertex(vertex142);
	auto vertex143 = new Vertex(213, 223);
	graph.AddVertex(vertex143);
	auto vertex144 = new Vertex(291, 283);
	graph.AddVertex(vertex144);
	auto vertex145 = new Vertex(259, 313);
	graph.AddVertex(vertex145);
	auto vertex146 = new Vertex(325, 357);
	graph.AddVertex(vertex146);
	auto vertex147 = new Vertex(242, 379);
	graph.AddVertex(vertex147);
	auto vertex148 = new Vertex(231, 428);
	graph.AddVertex(vertex148);
	auto vertex149 = new Vertex(195, 439);
	graph.AddVertex(vertex149);
	auto vertex150 = new Vertex(236, 528);
	graph.AddVertex(vertex150);
	auto vertex151 = new Vertex(252, 469);
	graph.AddVertex(vertex151);
	auto vertex152 = new Vertex(285, 469);
	graph.AddVertex(vertex152);
	auto vertex153 = new Vertex(292, 450);
	graph.AddVertex(vertex153);
	auto vertex154 = new Vertex(303, 415);
	graph.AddVertex(vertex154);
	auto vertex155 = new Vertex(268, 413);
	graph.AddVertex(vertex155);
	auto vertex156 = new Vertex(270, 384);
	graph.AddVertex(vertex156);
	auto vertex157 = new Vertex(345, 387);
	graph.AddVertex(vertex157);
	auto vertex158 = new Vertex(349, 430);
	graph.AddVertex(vertex158);
	auto vertex159 = new Vertex(400, 452);
	graph.AddVertex(vertex159);
	auto vertex160 = new Vertex(313, 488);
	graph.AddVertex(vertex160);
	auto vertex161 = new Vertex(308, 528);
	graph.AddVertex(vertex161);
	auto vertex162 = new Vertex(374, 472);
	graph.AddVertex(vertex162);
	auto vertex163 = new Vertex(423, 481);
	graph.AddVertex(vertex163);
	auto vertex164 = new Vertex(434, 519);
	graph.AddVertex(vertex164);
	auto vertex165 = new Vertex(493, 480);
	graph.AddVertex(vertex165);
	auto vertex166 = new Vertex(529, 427);
	graph.AddVertex(vertex166);
	auto vertex167 = new Vertex(526, 366);
	graph.AddVertex(vertex167);
	auto vertex168 = new Vertex(491, 367);
	graph.AddVertex(vertex168);
	auto vertex169 = new Vertex(478, 386);
	graph.AddVertex(vertex169);
	auto vertex170 = new Vertex(452, 340);
	graph.AddVertex(vertex170);
	auto vertex171 = new Vertex(417, 369);
	graph.AddVertex(vertex171);
	auto vertex172 = new Vertex(390, 404);
	graph.AddVertex(vertex172);
	auto vertex184 = new Vertex(171, 481);
	graph.AddVertex(vertex184);
	auto vertex200 = new Vertex(84, 402);
	graph.AddVertex(vertex200);
	auto vertex231 = new Vertex(214, 55);
	graph.AddVertex(vertex231);
	auto vertex232 = new Vertex(265, 56);
	graph.AddVertex(vertex232);
	auto vertex233 = new Vertex(336, 54);
	graph.AddVertex(vertex233);
	auto vertex234 = new Vertex(369, 54);
	graph.AddVertex(vertex234);
	auto vertex235 = new Vertex(376, 135);
	graph.AddVertex(vertex235);
	auto vertex236 = new Vertex(404, 171);
	graph.AddVertex(vertex236);
	auto vertex237 = new Vertex(331, 190);
	graph.AddVertex(vertex237);
	auto vertex238 = new Vertex(369, 210);
	graph.AddVertex(vertex238);
	auto vertex239 = new Vertex(343, 145);
	graph.AddVertex(vertex239);
	auto vertex240 = new Vertex(322, 103);
	graph.AddVertex(vertex240);
	auto vertex241 = new Vertex(294, 104);
	graph.AddVertex(vertex241);
	auto vertex242 = new Vertex(285, 134);
	graph.AddVertex(vertex242);
	auto vertex243 = new Vertex(278, 152);
	graph.AddVertex(vertex243);
	auto vertex244 = new Vertex(231, 142);
	graph.AddVertex(vertex244);
	auto vertex245 = new Vertex(187, 127);
	graph.AddVertex(vertex245);
	auto vertex248 = new Vertex(236, 183);
	graph.AddVertex(vertex248);
	auto vertex249 = new Vertex(253, 204);
	graph.AddVertex(vertex249);
	auto vertex255 = new Vertex(268, 84);
	graph.AddVertex(vertex255);
	auto vertex262 = new Vertex(220, 102);
	graph.AddVertex(vertex262);
	auto vertex266 = new Vertex(340, 85);
	graph.AddVertex(vertex266);
	auto vertex277 = new Vertex(313, 259);
	graph.AddVertex(vertex277);
	auto vertex280 = new Vertex(297, 184);
	graph.AddVertex(vertex280);
	auto vertex281 = new Vertex(313, 176);
	graph.AddVertex(vertex281);
	auto vertex282 = new Vertex(307, 206);
	graph.AddVertex(vertex282);
	auto vertex287 = new Vertex(309, 147);
	graph.AddVertex(vertex287);
	auto vertex304 = new Vertex(82, 201);
	graph.AddVertex(vertex304);
	auto vertex309 = new Vertex(268, 358);
	graph.AddVertex(vertex309);
	auto vertex311 = new Vertex(312, 375);
	graph.AddVertex(vertex311);
	auto vertex330 = new Vertex(355, 339);
	graph.AddVertex(vertex330);
	auto vertex343 = new Vertex(438, 313);
	graph.AddVertex(vertex343);
	auto vertex345 = new Vertex(490, 324);
	graph.AddVertex(vertex345);
	auto vertex348 = new Vertex(462, 303);
	graph.AddVertex(vertex348);
	auto vertex351 = new Vertex(468, 282);
	graph.AddVertex(vertex351);
	auto vertex352 = new Vertex(394, 232);
	graph.AddVertex(vertex352);
	auto vertex353 = new Vertex(429, 229);
	graph.AddVertex(vertex353);
	auto vertex354 = new Vertex(400, 272);
	graph.AddVertex(vertex354);
	auto vertex355 = new Vertex(397, 309);
	graph.AddVertex(vertex355);
	auto vertex356 = new Vertex(386, 341);
	graph.AddVertex(vertex356);
	auto vertex360 = new Vertex(384, 297);
	graph.AddVertex(vertex360);
	auto vertex364 = new Vertex(447, 273);
	graph.AddVertex(vertex364);
	auto vertex371 = new Vertex(524, 298);
	graph.AddVertex(vertex371);
	auto vertex372 = new Vertex(522, 199);
	graph.AddVertex(vertex372);
	auto vertex373 = new Vertex(468, 202);
	graph.AddVertex(vertex373);
	auto vertex374 = new Vertex(465, 228);
	graph.AddVertex(vertex374);
	auto vertex375 = new Vertex(475, 248);
	graph.AddVertex(vertex375);
	auto vertex383 = new Vertex(453, 145);
	graph.AddVertex(vertex383);
	auto vertex384 = new Vertex(418, 118);
	graph.AddVertex(vertex384);
	auto vertex385 = new Vertex(417, 31);
	graph.AddVertex(vertex385);
	auto vertex386 = new Vertex(420, 67);
	graph.AddVertex(vertex386);
	auto vertex387 = new Vertex(398, 94);
	graph.AddVertex(vertex387);
	auto vertex388 = new Vertex(451, 88);
	graph.AddVertex(vertex388);
	auto vertex389 = new Vertex(481, 110);
	graph.AddVertex(vertex389);
	auto vertex390 = new Vertex(476, 168);
	graph.AddVertex(vertex390);
	auto vertex391 = new Vertex(500, 151);
	graph.AddVertex(vertex391);
	auto vertex392 = new Vertex(546, 146);
	graph.AddVertex(vertex392);
	auto vertex393 = new Vertex(541, 103);
	graph.AddVertex(vertex393);
	auto vertex394 = new Vertex(531, 45);
	graph.AddVertex(vertex394);
	auto vertex395 = new Vertex(550, 24);
	graph.AddVertex(vertex395);
	auto vertex396 = new Vertex(470, 42);
	graph.AddVertex(vertex396);
	auto vertex432 = new Vertex(440, 424);
	graph.AddVertex(vertex432);
	graph.AddEdge(new Edge(vertex1, vertex104, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex103, vertex107, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex117, vertex107, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex117, vertex105, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex105, vertex104, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex104, vertex103, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex103, vertex113, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex113, vertex112, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex112, vertex107, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex107, vertex111, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex111, vertex184, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex184, vertex112, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex112, vertex114, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex184, vertex114, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex114, vertex113, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex117, vertex110, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex108, vertex117, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex110, vertex116, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex116, vertex111, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex110, vertex111, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex105, vertex109, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex109, vertex108, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex108, vertex115, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex115, vertex109, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex108, vertex200, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex200, vertex110, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex115, vertex200, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex114, vertex149, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex149, vertex116, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex116, vertex118, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex118, vertex115, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex114, vertex150, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex150, vertex151, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex151, vertex148, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex148, vertex149, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex148, vertex147, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex147, vertex137, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex137, vertex116, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex137, vertex136, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex136, vertex140, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex140, vertex141, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex141, vertex145, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex145, vertex137, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex136, vertex138, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex138, vertex139, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex139, vertex140, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex139, vertex119, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex119, vertex118, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex119, vertex135, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex135, vertex115, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex135, vertex134, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex134, vertex133, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex133, vertex132, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex132, vertex131, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex245, vertex244, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex244, vertex242, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex244, vertex248, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex248, vertex249, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex242, vertex243, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex242, vertex241, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex241, vertex240, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex241, vertex255, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex255, vertex232, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex232, vertex231, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex231, vertex131, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex131, vertex130, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex130, vertex262, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex262, vertex255, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex233, vertex232, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex240, vertex266, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex266, vertex233, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex233, vertex234, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex234, vertex235, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex235, vertex239, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex239, vertex240, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex239, vertex237, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex237, vertex238, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex238, vertex236, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex236, vertex235, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex277, vertex238, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex277, vertex249, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex282, vertex280, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex280, vertex249, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex280, vertex281, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex287, vertex281, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex287, vertex242, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex127, vertex126, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex126, vertex124, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex126, vertex128, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex128, vertex132, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex143, vertex126, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex143, vertex144, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex144, vertex277, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex144, vertex145, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex143, vertex142, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex142, vertex141, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex119, vertex120, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex120, vertex123, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex120, vertex121, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex121, vertex122, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex134, vertex304, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex124, vertex125, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex123, vertex124, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex146, vertex145, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex309, vertex156, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex146, vertex311, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex311, vertex156, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex156, vertex155, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex155, vertex153, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex153, vertex154, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex153, vertex152, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex152, vertex151, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex152, vertex160, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex160, vertex161, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex161, vertex150, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex161, vertex164, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex164, vertex163, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex163, vertex162, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex162, vertex160, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex159, vertex158, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex158, vertex153, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex158, vertex157, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex157, vertex311, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex330, vertex146, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex330, vertex144, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex171, vertex172, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex165, vertex164, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex165, vertex166, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex166, vertex167, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex167, vertex168, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex168, vertex169, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex169, vertex170, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex171, vertex170, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex343, vertex170, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex345, vertex168, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex348, vertex345, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex348, vertex343, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex330, vertex356, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex356, vertex171, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex356, vertex355, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex355, vertex360, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex360, vertex277, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex360, vertex354, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex364, vertex354, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex354, vertex352, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex352, vertex353, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex353, vertex364, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex364, vertex351, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex348, vertex351, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex375, vertex351, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex375, vertex374, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex374, vertex373, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex373, vertex372, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex372, vertex371, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex371, vertex167, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex373, vertex236, WEIGHT_LANE));
	graph.AddEdge(new Edge(vertex395, vertex394, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex394, vertex396, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex396, vertex385, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex385, vertex386, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex385, vertex234, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex234, vertex386, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex386, vertex387, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex387, vertex384, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex384, vertex388, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex388, vertex386, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex388, vertex396, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex388, vertex389, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex389, vertex383, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex384, vertex383, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex383, vertex236, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex236, vertex384, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex383, vertex390, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex390, vertex391, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex391, vertex389, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex389, vertex393, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex393, vertex392, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex392, vertex391, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex391, vertex372, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex372, vertex392, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex393, vertex394, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex352, vertex238, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex129, vertex128, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex129, vertex130, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex245, vertex129, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex245, vertex130, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex249, vertex143, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex122, vertex304, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex125, vertex304, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex159, vertex163, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex432, vertex171, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex432, vertex159, WEIGHT_NORMAL));
	graph.AddEdge(new Edge(vertex432, vertex165, WEIGHT_WATER));
	graph.AddEdge(new Edge(vertex351, vertex371, WEIGHT_NORMAL));
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
	auto cow = new Cow(application, graph.GetVertex());
	Sleep(1000);
	auto rabbit = new Rabbit(application, graph.GetVertex());

	Astar astar;
	
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
				case SDLK_f:
					cow->FindRabbit(rabbit->GetPosition());
					break;
				case SDLK_SPACE: // move cow
					cow->Mooove();
					break;
				case SDLK_0:
					cow->MoveToRabbit(rabbit->GetPosition());
					break;
				default:
					break;
				}
			}
		}
		
		if (cow->GetPositionID() == rabbit->GetPositionID())
			rabbit->Move(graph.GetVertex());

		//Week1	
		graph.DrawGraph(application);
		cow->Draw();
		rabbit->Draw();
		
		
		
		
		
		// For the background
		application->SetColor(Color(220, 220, 220, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}