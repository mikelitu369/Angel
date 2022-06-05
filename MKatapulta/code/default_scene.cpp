

#include <default_scene.hpp>
#include <vector>
#include <transform.hpp>

namespace MKatapulta
{
	Default_Scene::Default_Scene(const std::string& name, Window& window) : Scene(name, window) {}

	void Default_Scene::setup()
	{
#pragma region Luz
		Entity* luz = new Entity(this);
		glm::vec3 posicion_luz(10, 10, 10);
		luz->get_transform()->set_local_position(posicion_luz);
		luz->add_component(renderer_system->create_light("luz"));
#pragma endregion

#pragma region Catapulta
		Entity* catapulta = new Entity(this);
		{
			glm::vec3 posicion_catapulta(-25, 0, 15);
			glm::vec3 rotation_catapulta(0, 0, 0);
			catapulta->get_transform()->set_local_position(posicion_catapulta);
			catapulta->get_transform()->set_local_rotatoin(rotation_catapulta);
			entidades_reset.push_back(catapulta);
			posiciones_originales.push_back(posicion_catapulta);	
			rotaciones_originales.push_back(rotation_catapulta);

			Entity* camera = new Entity(this, catapulta->get_transform());
			glm::vec3 posicion_camara(0, 3, 5);
			glm::vec3 rotation_camara(-0.2f, 0, 0);
			camera->get_transform()->set_local_position(posicion_camara);
			camera->get_transform()->set_local_rotatoin(rotation_camara);
			camera->add_component(renderer_system->create_camera("main_camera"));

			float radioRuedas = 0.3f;
			float ancho = 1;
			float largo = 2;

			Entity* catapulta_body = new Entity(this, catapulta->get_transform());
			glm::vec3 posicion_catapulta_body(0, radioRuedas / 2, 0);
			glm::vec3 escala_catapulta_body(ancho, radioRuedas / 2, largo);
			catapulta_body->get_transform()->set_local_position(posicion_catapulta_body);
			catapulta_body->get_transform()->set_local_scale(escala_catapulta_body);
			catapulta_body->add_component(renderer_system->create_mesh("catapulta_body", "../models/cube.obj"));

			{
				Entity* rueda = new Entity(this, catapulta->get_transform());
				glm::vec3 posicion_rueda(ancho / 2, radioRuedas / 2, largo / 2);
				glm::vec3 escala_rueda(radioRuedas, radioRuedas, radioRuedas);
				rueda->get_transform()->set_local_position(posicion_rueda);
				rueda->get_transform()->set_local_scale(escala_rueda);
				rueda->add_component(renderer_system->create_mesh("rueda1", "../models/sphere.obj"));
			}

			{
				Entity* rueda = new Entity(this, catapulta->get_transform());
				glm::vec3 posicion_rueda(-ancho / 2, radioRuedas / 2, largo / 2);
				glm::vec3 escala_rueda(radioRuedas, radioRuedas, radioRuedas);
				rueda->get_transform()->set_local_position(posicion_rueda);
				rueda->get_transform()->set_local_scale(escala_rueda);
				rueda->add_component(renderer_system->create_mesh("rueda2", "../models/sphere.obj"));
			}

			{
				Entity* rueda = new Entity(this, catapulta->get_transform());
				glm::vec3 posicion_rueda(ancho / 2, radioRuedas / 2, -largo / 2);
				glm::vec3 escala_rueda(radioRuedas, radioRuedas, radioRuedas);
				rueda->get_transform()->set_local_position(posicion_rueda);
				rueda->get_transform()->set_local_scale(escala_rueda);
				rueda->add_component(renderer_system->create_mesh("rueda3", "../models/sphere.obj"));
			}

			{
				Entity* rueda = new Entity(this, catapulta->get_transform());
				glm::vec3 posicion_rueda(-ancho / 2, radioRuedas / 2, -largo / 2);
				glm::vec3 escala_rueda(radioRuedas, radioRuedas, radioRuedas);
				rueda->get_transform()->set_local_position(posicion_rueda);
				rueda->get_transform()->set_local_scale(escala_rueda);
				rueda->add_component(renderer_system->create_mesh("rueda4", "../models/sphere.obj"));
			}

			Entity* eje = new Entity(this, catapulta->get_transform());
			glm::vec3 posicion_eje(0, radioRuedas, 0);
			glm::vec3 rotacion_eje(3.14f/2, 0, 0);
			eje->get_transform()->set_local_position(posicion_eje);
			eje->get_transform()->set_local_rotatoin(rotacion_eje);

			Entity* palo = new Entity(this, eje->get_transform());
			glm::vec3 posicion_palo(0, 0, 0);
			glm::vec3 escala_palo(ancho/5, largo * 0.75f, ancho / 5);
			palo->get_transform()->set_local_position(posicion_palo);
			palo->get_transform()->set_local_scale(escala_palo);
			palo->add_component(renderer_system->create_mesh("palo", "../models/cube.obj"));

			Entity* canasta = new Entity(this, eje->get_transform());
			glm::vec3 posicion_canasta(0, largo * 0.75f, 0);
			glm::vec3 escala_canasta(ancho / 3, ancho / 3, ancho / 3);
			canasta->get_transform()->set_local_position(posicion_canasta);
			canasta->get_transform()->set_local_scale(escala_canasta);
			canasta->add_component(renderer_system->create_mesh("canasta", "../models/sphere.obj"));

			catapulta->add_component(controller_system->create_catapulta_controller(eje->get_transform()));
		}
#pragma endregion
		
#pragma region Islas
		Entity* isla0 = new Entity(this);
		glm::vec3 posicion_isla0(-25, -1, 10);
		glm::vec3 escala_isla0(10, 1, 30);
		isla0->get_transform()->set_local_position(posicion_isla0);
		isla0->get_transform()->set_local_scale(escala_isla0);
		isla0->add_component(renderer_system->create_mesh("isla0", "../models/cube.obj"));
		isla0->add_component(controller_system->create_suelo(catapulta->get_transform()));

		Entity* isla1 = new Entity(this);
		glm::vec3 posicion_isla1(-15, -1, -10);
		glm::vec3 escala_isla1(30, 1, 10);
		isla1->get_transform()->set_local_position(posicion_isla1);
		isla1->get_transform()->set_local_scale(escala_isla1);
		isla1->add_component(renderer_system->create_mesh("isla1", "../models/cube.obj"));
		isla1->add_component(controller_system->create_suelo(catapulta->get_transform()));
		
		Entity* isla2 = new Entity(this);
		glm::vec3 posicion_isla2(40, -1, -10);
		glm::vec3 escala_isla2(10, 1, 30);
		isla2->get_transform()->set_local_position(posicion_isla2);
		isla2->get_transform()->set_local_scale(escala_isla2);
		isla2->add_component(renderer_system->create_mesh("isla2", "../models/cube.obj"));
		isla2->add_component(controller_system->create_suelo(catapulta->get_transform()));

		Entity* isla3 = new Entity(this);
		glm::vec3 posicion_isla3(55, -1, -10);
		glm::vec3 escala_isla3(2, 1, 2);
		isla3->get_transform()->set_local_position(posicion_isla3);
		isla3->get_transform()->set_local_scale(escala_isla3);
		isla3->add_component(renderer_system->create_mesh("isla3", "../models/cube.obj"));
		isla3->add_component(controller_system->create_suelo(catapulta->get_transform()));
#pragma endregion

#pragma region Puerta
		Entity* puerta = new Entity(this);
		glm::vec3 puerta_position(20, -25, -10);
		puerta->get_transform()->set_local_position(puerta_position);

		Entity* muro1 = new Entity(this, puerta->get_transform());
		glm::vec3 muro1_position(0, 0, 50);
		glm::vec3 muro1_scale(1, 50, 100);
		muro1->get_transform()->set_local_position(muro1_position);
		muro1->get_transform()->set_local_scale(muro1_scale);
		muro1->add_component(renderer_system->create_mesh("muro1", "../models/cube.obj"));

		Entity* muro2 = new Entity(this, puerta->get_transform());
		glm::vec3 muro2_position(0, 0, -50);
		glm::vec3 muro2_scale(1, 50, 100);
		muro2->get_transform()->set_local_position(muro2_position);
		muro2->get_transform()->set_local_scale(muro2_scale);
		muro2->add_component(renderer_system->create_mesh("muro2", "../models/cube.obj"));

		Puerta_Controller* puerta_controller = controller_system->create_puerta(muro1->get_transform(), muro2->get_transform());
		puerta->add_component(puerta_controller);
#pragma endregion

#pragma region Platform
		Entity* platform = new Entity(this);
		glm::vec3 posicion_platform(2, -5, -10);
		glm::vec3 escala_platform(4, 1, 4);
		platform->get_transform()->set_local_position(posicion_platform);
		platform->get_transform()->set_local_scale(escala_platform);
		platform->add_component(renderer_system->create_mesh("platform", "../models/cube.obj"));
		platform->add_component(controller_system->create_suelo(catapulta->get_transform()));

		Platform_Controller* platform_controller = controller_system->create_platform(catapulta->get_transform());
		platform->add_component(platform_controller);
#pragma endregion

#pragma region Llave
		Entity* llave = new Entity(this);
		glm::vec3 llave_position(-15, 0.5, -10);
		llave->get_transform()->set_local_position(llave_position);

		Entity* giro_cubo = new Entity(this, llave->get_transform());
		glm::vec3 giro_cubo_rotation(3.14 / 4, 0, 3.14 / 4);
		glm::vec3 giro_cubo_scale(0.5, 0.5, 0.5);
		giro_cubo->get_transform()->set_local_rotatoin(giro_cubo_rotation);
		giro_cubo->get_transform()->set_local_scale(giro_cubo_scale);
		giro_cubo->add_component(renderer_system->create_mesh("giro_cubo", "../models/cube.obj"));

		llave->add_component(controller_system->create_key(catapulta->get_transform(), platform_controller, puerta_controller, giro_cubo->get_transform()));
#pragma endregion


	}
	void Default_Scene::reset()
	{
		for (size_t i = 0; i < entidades_reset.size(); i++)
		{
			entidades_reset[i]->get_transform()->set_local_position(posiciones_originales[i]);
			entidades_reset[i]->get_transform()->set_local_rotatoin(rotaciones_originales[i]);
		}
	}
}