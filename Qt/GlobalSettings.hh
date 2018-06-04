//
// Created by dima on 04.06.18.
//

#ifndef PROJECT_GLOBALSETTINGS_HH
#define PROJECT_GLOBALSETTINGS_HH

class GlobalSettings{

    int m_ai_max_level = 80;
    int m_shuffle_count = 40;
    float m_animation_speed = 1100.0;

    GlobalSettings() = default;
public:

    void setAiMaxLevel(int ai_max_level){
        m_ai_max_level = ai_max_level;
        std::cout<<m_ai_max_level<<std::endl;
    }

    void setShuffleCount(int shuffle_count){
        m_shuffle_count = shuffle_count;
        std::cout<<m_shuffle_count<<std::endl;
    }

    void setAiMaxLevel(float animation_speed){
        m_animation_speed = animation_speed;
        std::cout<<m_animation_speed<<std::endl;
    }

    int getAiMaxLevel() const {
        return m_ai_max_level;
    }

    int getShuffleCount() const {
        return m_shuffle_count;
    }

    float getAnimationSpeed() const {
        return m_animation_speed;
    }

    static GlobalSettings& get(){
        static GlobalSettings gs;
        return gs;
    }


};

#endif //PROJECT_GLOBALSETTINGS_HH