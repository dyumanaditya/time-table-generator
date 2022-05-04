#ifndef COURSES_H
#define COURSES_H

#include <vector>
#include <string>


enum Courses
{
    // Total 110
    // Math
    Mathematics,
    Additional_Mathematics,
    Subsidary_Mathematics,
    Mathematical_Statistics,
    Elementary_Statistics,
    Numerical_Analysis,
    Linear_Algebra,

    // Computer
    Computer_Applications,
    Computer_Programming_In_CPP,
    Advanced_Electronics,
    Basic_Electronics,
    Subjects_In_Technology,

    // Physics
    Physics_K3,
    Physics_K1,
    Physics_K2,
    Additional_Phyisics,

    // Chemistry
    Chemistry_K1,
    Chemistry_K2,
    Chemistry_K3,
    Additional_Chemistry,

    // Solar Science
    Solar_Science,
    Environmental_Sustainability,

    // Biology
    Biology,

    // History
    History,
    History_Of_Ancient_And_Early_Medieval_India,
    History_Of_Art,

    // Languages
    English,
    French,
    German,
    Spanish,
    Manderin,
    Japanese,
    Italian,
    Russian,
    Tibetan,

    Tamil,
    Telegu,
    Bengali,
    Oriya,
    Hindi,
    Gujrati,
    Sanskrit,
    Kannada,
    Malayalayam,
    Marathi,

    // Sri Aurobindo
    The_Ideal_Of_Human_Unity,
    The_Human_Cycle,
    The_Synthesis_Of_Yoga,
    The_Foundations_Of_Indian_Culture,
    Savitri,
    The_Life_Divine,
    Essays_On_The_Gita,
    The_Future_Poetry,
    Sri_Aurobindos_Poetry,
    War_And_Self_Determination,
    The_Secret_Of_The_Veda,
    Letters_On_Yoga,
    Studies_Of_The_Mothers_Works_French,
    Integral_Psychology_Of_Sri_Aurobindo,
    The_Gita_In_The_Light_And_Vision_Of_Sri_Aurobindo,
    Social_Philosophy_Of_Sri_Aurobindo,
    Sri_Aurobindo_And_The_Mother_On_Education,
    Sri_Aurobindo_And_The_Mother_On_Physical_Education,
    The_Yoga_Of_Self_Perfection,
    Sri_Aurobindo_And_World_Philosophy,

    // Philosophy
    Introduction_To_Philosophy,
    Psychology,
    Consciousness_Studies,
    Indian_Philosophy,
    Indian_And_Western_Philosophy,

    // Global
    Governance_And_Politics,
    Global_And_International_Studies,
    Sociology,
    Human_Geography,
    Political_Science,
    Principles_Of_Economics,

    // Misc
    Critical_Thinking,
    Management,
    Architechture_And_Design,
    Design_And_Interiors,
    Indian_Aesthetics,
    Introduction_To_Social_Anthropology,
    Physical_Education,
    Photography,
    Cinematography,

    // Handwork
    Carpentry,
    Drawing_And_Painting,
    Craft,
    Pottery,
    Eco_Lake_Project,

    // Music
    Karnatic_Vocal,
    Hindustani_Vocal,
    Violin,
    Piano,
    Sitar,
    Tabla,
    Flute
};

std::vector<std::string> Fixed_Period_Courses = {
    // Math
    "Mathematics",
    "Additional_Mathematics",
    "Subsidary_Mathematics",
    "Mathematical_Statistics",
    "Elementary_Statistics",
    "Numerical_Analysis",
    "Linear_Algebra",

    // Computer
    "Computer_Applications",
    "Computer_Literacy",
    "Computer_Programming_In_CPP",

    // Physics
    "Physics_K3",
    "Physics_K1",
    "Physics_K2",
    "Additional_Phyisics",

    // Chemistry
    "Chemistry_K1",
    "Chemistry_K2",
    "Chemistry_K3",
    "Additional_Chemistry",

    // Solar Science
    "Solar_Science",
    "Environmental_Sustainability",

    // Biology
    "Biology",
    "Molecular_And_Cellular_Biochemistry",
    "Genetics",
    "Basic_Medical_Physiology",
    "Zoology",
    "Botany",
    "Tissue_Culture",
    "Health_Studies",
    "Embryology",
    "Evolution",
    "Ecology",
    "Animal_Behaviour",
    "Marine_Biology",
};
#endif // COURSES_H
