#include "UI.h"
#include <glm/gtc/type_ptr.hpp>

void DarkTheme();

UI::UI(GLFWwindow* window) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	DarkTheme();
}

UI::~UI() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void UI::begin() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void UI::render(World *world) {
	ImGui::Begin("CraftGL");

	ImGui::Text("Stats: %.1f FPS", ImGui::GetIO().Framerate);
	ImGui::Separator();

	ImGui::Checkbox("Auto-rotate Mesh", &world->auto_rotate);

	if (!world->meshes.empty()) {
		Mesh* m = world->meshes[0];

		if (!(world->auto_rotate)) {
			ImGui::SliderFloat3("Rotation", glm::value_ptr(m->get_rotation()), 0.0f, 6.28f);
		} else {
			ImGui::Text("Rotation controlled by World::update()");
		}

		ImGui::SliderFloat3("Position", glm::value_ptr(m->get_position()), -5.0f, 5.0f);
		ImGui::SliderFloat("Scale", &m->get_scale().x, 0.1f, 3.0f); 
		float s = m->get_scale().x;
		m->set_scale(glm::vec3(s, s, s));
	}

	ImGui::End();
}

void UI::end() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void DarkTheme() {
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	style.WindowRounding    = 0.0f;
	style.FrameRounding     = 0.0f;
	style.WindowBorderSize  = 1.0f;
	style.FrameBorderSize   = 1.0f;

	colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.90f);

	colors[ImGuiCol_ResizeGrip]         = ImVec4(0.30f, 0.30f, 0.30f, 0.25f);
	colors[ImGuiCol_ResizeGripHovered]  = ImVec4(0.50f, 0.50f, 0.50f, 0.67f);
	colors[ImGuiCol_ResizeGripActive]   = ImVec4(0.80f, 0.80f, 0.80f, 0.95f);

	colors[ImGuiCol_FrameBg]            = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
	colors[ImGuiCol_FrameBgHovered]     = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);
	colors[ImGuiCol_FrameBgActive]      = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);

	colors[ImGuiCol_SliderGrab]         = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
	colors[ImGuiCol_SliderGrabActive]   = ImVec4(0.55f, 0.55f, 0.55f, 1.00f);

	colors[ImGuiCol_Border]             = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	colors[ImGuiCol_Text]               = ImVec4(0.85f, 0.85f, 0.85f, 1.00f);
	colors[ImGuiCol_TitleBg]            = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive]      = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_CheckMark]          = ImVec4(0.70f, 0.70f, 0.70f, 1.00f);

	colors[ImGuiCol_Header]                = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
	colors[ImGuiCol_HeaderHovered]         = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_HeaderActive]          = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);

	colors[ImGuiCol_Separator]             = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_SeparatorActive]       = ImVec4(0.70f, 0.70f, 0.70f, 1.00f);

	colors[ImGuiCol_NavHighlight]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
}
