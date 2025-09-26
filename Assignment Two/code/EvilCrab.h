#pragma once

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>

namespace godot {

    class EvilCrab : public Sprite2D {
        GDCLASS(EvilCrab, Sprite2D)

    private:
        float speed;
        float screen_bottom;
        Area2D* hitbox;

        float left_limit;   // left edge of patrol
        float right_limit;  // right edge of patrol
        int direction;      // 1 = right, -1 = left

    protected:
        static void _bind_methods();

    public:
        EvilCrab();
        ~EvilCrab();

        void _ready() override;
        void _process(double delta) override;

        void on_body_entered(Node* body);

        void stop_moving();

        void set_speed(float p_speed);
        float get_speed() const;
    };

}


