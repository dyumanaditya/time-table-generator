#ifndef COURSES_H
#define COURSES_H

#include <vector>
#include <string>


enum Courses
{
    // total 110
    // math
    mathematics,
    additional_mathematics,
    subsidary_mathematics,
    mathematical_statistics,
    elementary_statistics,
    numerical_analysis,
    linear_algebra,

    // computer
    computer_applications,
    computer_programming_in_cpp,
    advanced_electronics,
    basic_electronics,
    subjects_in_technology,

    // physics
    physics_k3,
    physics_k1,
    physics_k2,
    additional_phyisics,

    // chemistry
    chemistry_k1,
    chemistry_k2,
    chemistry_k3,
    additional_chemistry,

    // solar science
    solar_science,
    environmental_sustainability,

    // biology
    biology,

    // history
    history,
    history_of_ancient_and_early_medieval_india,
    history_of_art,

    // languages
    english,
    french,
    german,
    spanish,
    manderin,
    japanese,
    italian,
    russian,
    tibetan,

    tamil,
    telegu,
    bengali,
    oriya,
    hindi,
    gujrati,
    sanskrit,
    kannada,
    malayalayam,
    marathi,

    // sri aurobindo
    the_ideal_of_human_unity,
    the_human_cycle,
    the_synthesis_of_yoga,
    the_foundations_of_indian_culture,
    savitri,
    the_life_divine,
    essays_on_the_gita,
    the_future_poetry,
    sri_aurobindos_poetry,
    war_and_self_determination,
    the_secret_of_the_veda,
    letters_on_yoga,
    studies_of_the_mothers_works_french,
    integral_psychology_of_sri_aurobindo,
    the_gita_in_the_light_and_vision_of_sri_aurobindo,
    social_philosophy_of_sri_aurobindo,
    sri_aurobindo_and_the_mother_on_education,
    sri_aurobindo_and_the_mother_on_physical_education,
    the_yoga_of_self_perfection,
    sri_aurobindo_and_world_philosophy,

    // philosophy
    introduction_to_philosophy,
    psychology,
    consciousness_studies,
    indian_philosophy,
    indian_and_western_philosophy,

    // global
    governance_and_politics,
    global_and_international_studies,
    sociology,
    human_geography,
    political_science,
    principles_of_economics,

    // misc
    critical_thinking,
    management,
    architechture_and_design,
    design_and_interiors,
    indian_aesthetics,
    introduction_to_social_anthropology,
    physical_education,
    photography,
    cinematography,

    // handwork
    carpentry,
    drawing_and_painting,
    craft,
    pottery,
    eco_lake_project,

    // music
    karnatic_vocal,
    hindustani_vocal,
    violin,
    piano,
    sitar,
    tabla,
    flute
};

std::vector<std::string> fixed_period_courses = {
    // math
    "mathematics",
    "mathematical_statistics",
    "elementary_statistics",
    "numerical_analysis",
    "linear_algebra",

    // computer
    "computer_applications",
    "computer_literacy",
    "computer_programming_in_cpp",

    // physics
    "physics_k3",
    "physics_k1",
    "physics_k2",

    // chemistry
    "chemistry_k1",
    "chemistry_k2",
    "chemistry_k3",

    // solar science
    "solar_science",

    // biology
    "biology",
};
#endif // COURSES_H
