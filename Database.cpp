#include "Database.h"

Database::Database() : recordCount(0) {}

void Database::begin() {
    clear();
}

void Database::clear() {
    for (size_t i = 0; i < MAX_RECORDS; i++) {
        records[i].isUsed = false;
        records[i].key[0] = '\0';
        records[i].value[0] = '\0';
    }
    recordCount = 0;
}

bool Database::insert(const char* key, const char* value) {
    if (!key || !value) return false;

    for (size_t i = 0; i < MAX_RECORDS; i++) {
        if (records[i].isUsed && strcmp(records[i].key, key) == 0) {
            strncpy(records[i].value, value, MAX_VAL_LEN - 1);
            records[i].value[MAX_VAL_LEN - 1] = '\0';
            return true;
        }
    }

    if (recordCount >= MAX_RECORDS) return false;

    for (size_t i = 0; i < MAX_RECORDS; i++) {
        if (!records[i].isUsed) {
            strncpy(records[i].key, key, MAX_KEY_LEN - 1);
            records[i].key[MAX_KEY_LEN - 1] = '\0';

            strncpy(records[i].value, value, MAX_VAL_LEN - 1);
            records[i].value[MAX_VAL_LEN - 1] = '\0';

            records[i].isUsed = true;
            recordCount++;
            return true;
        }
    }

    return false;
}

bool Database::get(const char* key, char* buffer, size_t bufferSize) const {
    if (!key || !buffer || bufferSize == 0) return false;

    for (size_t i = 0; i < MAX_RECORDS; i++) {
        if (records[i].isUsed && strcmp(records[i].key, key) == 0) {
            strncpy(buffer, records[i].value, bufferSize - 1);
            buffer[bufferSize - 1] = '\0';
            return true;
        }
    }

    return false;
}

size_t Database::count() const {
    return recordCount;
}

void Database::loadPackage(uint8_t packageId) {
    clear();
    switch(packageId) {
        case 1:
            insert("q1", "Does your character wear a high-tech armored suit? (y/n)");
            insert("q2", "Does your character have a lightning bolt scar? (y/n)");
            insert("iron_man", "Tony Stark - Billionaire industrialist and Avenger.");
            insert("spider_man", "Peter Parker - Wall-crawling superhero.");
            insert("harry_potter", "The Boy Who Lived and wizard of Hogwarts.");
            break;
        case 2:
            insert("einstein", "Albert Einstein formulated the theory of relativity (E=mc^2).");
            insert("curie", "Marie Curie discovered radium and polonium, pioneering radioactivity.");
            break;
        case 3:
            insert("shakespeare", "English playwright and poet known for Hamlet and Macbeth.");
            insert("dickens", "Victorian novelist who wrote Oliver Twist and A Christmas Carol.");
            break;
        case 4:
            insert("caesar", "Roman general and statesman who shaped the Roman Republic.");
            insert("lincoln", "16th US President who led the nation through the Civil War.");
            break;
        case 5:
            insert("turing", "Father of modern computer science and artificial intelligence.");
            insert("ritchie", "Creator of the C programming language and co-creator of Unix.");
            break;
        case 6:
            insert("socrates", "Classical Greek philosopher known for foundational questioning methods.");
            insert("plato", "Philosopher, mathematician, and founder of the Academy in Athens.");
            break;
        case 7:
            insert("davinci", "Italian Renaissance polymath, scientist, and painter of the Mona Lisa.");
            insert("vangogh", "Dutch Post-Impressionist painter of The Starry Night.");
            break;
        case 8:
            insert("beethoven", "German composer who bridged the classical and romantic eras.");
            insert("mozart", "Prolific child prodigy and composer of the Classical era.");
            break;
        case 9:
            insert("everest", "Earth's highest mountain peak standing at 8,848 meters.");
            insert("nile", "Longest river in Africa flowing northward into the Mediterranean.");
            break;
        case 10:
            insert("armstrong", "American astronaut who commanded Apollo 11 and walked on the Moon.");
            insert("sagan", "Renowned astronomer, astrobiologist, and science popularizer.");
            break;
        case 11:
            insert("edison", "Prolific American inventor holding over 1,000 patents.");
            insert("tesla", "Serbian-American visionary in electrical engineering and AC power.");
            break;
        case 12:
            insert("pythagoras", "Ancient Greek philosopher and mathematician of the Pythagorean theorem.");
            insert("euclid", "Ancient Greek mathematician referred to as the father of geometry.");
            break;
        case 13:
            insert("newton", "Formulated the laws of motion and universal gravitation.");
            insert("hawking", "Theoretical physicist renowned for work on black holes.");
            break;
        case 14:
            insert("pasteur", "French chemist renowned for principles of vaccination and pasteurization.");
            insert("fleming", "Scottish physician who discovered the world's first antibiotic.");
            break;
        case 15:
            insert("darwin", "Naturalist who voyaged on the HMS Beagle and proposed natural selection.");
            insert("franklin", "Chemist whose X-ray diffraction data revealed DNA's double helix.");
            break;
        case 16:
            insert("colosseum", "Large elliptical amphitheater in the center of Rome, Italy.");
            insert("taj", "White marble mausoleum located in Agra, India.");
            break;
        case 17:
            insert("zeus", "Ruler of Mount Olympus and god of sky, lightning, and thunder.");
            insert("thor", "Norse deity associated with thunder, lightning, storms, and strength.");
            break;
        case 18:
            insert("tarantino", "Celebrated American filmmaker known for sharp dialogue and cinematic flair.");
            insert("nolan", "British-American director famous for practical effects and complex narratives.");
            break;
        case 19:
            insert("chomsky", "American linguist, philosopher, and cognitive scientist.");
            insert("webster", "Lexicographer known for the American Dictionary of the English Language.");
            break;
        case 20:
            insert("smith", "Scottish economist and philosopher known as the father of modern economics.");
            insert("keynes", "English economist whose ideas fundamentally changed macroeconomics.");
            break;
        case 21:
            insert("durkheim", "One of the principal architects of modern social science.");
            insert("weber", "German sociologist, historian, jurist, and political economist.");
            break;
        case 22:
            insert("hippocrates", "Ancient Greek physician considered one of the most outstanding figures in medicine.");
            insert("jenner", "English physician and scientist who pioneered the concept of vaccines.");
            break;
        case 23:
            insert("amazon", "Vast tropical rainforest spanning South America.");
            insert("reef", "Great Barrier Reef composed of over 2,900 individual reefs.");
            break;
        case 24:
            insert("confucius", "Chinese philosopher and politician of the Spring and Autumn period.");
            insert("buddha", "Sramana who lived in ancient India and founded Buddhism.");
            break;
        case 25:
            insert("galileo", "Father of observational astronomy and modern physics.");
            insert("copernicus", "Renaissance mathematician and astronomer who formulated a heliocentric model.");
            break;
        default:
            break;
    }
}
