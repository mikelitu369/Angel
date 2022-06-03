

#include <default_scene.hpp>
#include <vector>
#include <transform.hpp>


namespace MKatapulta
{
	Default_Scene::Default_Scene(const std::string& name, Window& window) : Scene(name, window) {}

	void Default_Scene::setup()
	{
		Entity* luz = new Entity(this);
		glm::vec3 posicion_luz(10, 10, 10);
		luz->get_transform()->set_local_position(posicion_luz);
		luz->add_component(renderer_system->create_light("luz"));

		//Catapulta
		Entity* catapulta = new Entity(this);
		{
			glm::vec3 posicion_catapulta(0, 0, 0);
			catapulta->get_transform()->set_local_position(posicion_catapulta);
			entidades_reset.push_back(catapulta);
			posiciones_originales.push_back(posicion_catapulta);

			Entity* liebre = new Entity(this, catapulta->get_transform());
			glm::vec3 posicion_liebre(0, 0, 1);
			liebre->get_transform()->set_local_position(posicion_liebre);

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

			catapulta->add_component(controller_system->create_catapulta_controller(liebre->get_transform(), eje->get_transform()));
		}
		
		Entity* isla1 = new Entity(this);
		glm::vec3 posicion_isla1(0, -1, -15);
		glm::vec3 escala_isla1(10, 1, 40);
		isla1->get_transform()->set_local_position(posicion_isla1);
		isla1->get_transform()->set_local_scale(escala_isla1);
		isla1->add_component(renderer_system->create_mesh("isla1", "../models/cube.obj"));
		isla1->add_component(controller_system->create_suelo(catapulta->get_transform()));
		

		Entity* isla2 = new Entity(this);
		glm::vec3 posicion_isla2(7, -1, -15);
		glm::vec3 escala_isla2(4, 1, 4);
		isla2->get_transform()->set_local_position(posicion_isla2);
		isla2->get_transform()->set_local_scale(escala_isla2);
		isla2->add_component(renderer_system->create_mesh("isla2", "../models/cube.obj"));
		isla2->add_component(controller_system->create_suelo(catapulta->get_transform()));



	}
	void Default_Scene::reset()
	{
		for (size_t i = 0; i < entidades_reset.size(); i++)
		{
			entidades_reset[i]->get_transform()->set_local_position(posiciones_originales[i]);
		}
	}
}