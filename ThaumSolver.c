#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODES 70

enum aspects{
    Aer,            //NULL_ASPECT, NULL_ASPECT
    Alienis,        //Vacuos, Tenebrae
    Aqua,           //NULL_ASPECT,NULL_ASPECT
    Arbor,          //Aer, Herba
    Auram,          //Praecantatio, Aer
    Bestia,         //Motus, Victus
    Cognitio,       //Ignis, Spiritus
    Corpus,         //Mortuus, Bestia
    Desidia,        //Vinculum, Spiritus
    Electrum,       //Potentia, Machina
    Exanimis,       //Motus, Mortuus
    Fabrico,        //Humanus, Instrumentum
    Fames,          //Victus, Vacuos, 
    Gelum,          //Ignis, Perditio
    Gloria,         //Humanus, Iter
    Gula,           //Fames, Vacuos
    Herba,          //Victus, Terra
    Humanus,        //Bestia, Cognitio
    Ignis,          //NULL_ASPECT, NULL_ASPECT
    Infernus,       //Ignis, Praecantatio
    Instrumentum,   //Humanus, Ordo
    Invidia,        //Sensus, Fames
    Ira,            //Telum, Ignis
    Iter,           //Motus, Terra
    Limus,          //Victus, Aqua
    Lucrum,         //Humanus, Fames
    Lux,            //Aer, Ignis
    Luxuria,        //Corpus, Fames
    Machina,        //Motus, Instrumentum
    Magneto,        //Metallum, Iter
    Messis,         //Herba, Humanus
    Metallum,       //Terra, Vitreus
    Meto,           //Messis, Nebrisum
    Mortuus,        //Victus, Perdito
    Motus,          //Aer, Ordo
    Nebrisum,       //Lucrum,  Perfodio
    Ordo,           //NULL_ASPECT, NULL_ASPECT
    Pannus,         //Instrumentum, Bestia
    Perditio,       //NULL_ASPECT, NULL_ASPECT
    Perfodio,       //Humanus, Terra
    Permutatio,     //Perdito, Ordo
    Potentia,       //Ordo, Ignis
    Praecantatio,   //Vacuos, Potentia
    Radio,          //Potentia + Lux
    Sano,           //Victus, Ordo
    Sensus,         //Aer, Spiritus
    Spiritus,       //Victus, Mortuus
    Strontio,       //Perditio, Cognitio
    Superbia,       //Volatus, Vacuos
    Telum,          //Instrumentum, Ignis
    Tempestas,      //Aer, Aqua
    Tempus,         //Vacuos,  Ordo
    Tenebrae,       //Vacuos, Lux
    Terminus,       //Alienis, Lucrum 
    Terra,          //NULL_ASPECT, NULL_ASPECT
    Tutamen,        //Instrumentum, Terra
    Vacuos,         //Aer, Perditio
    Venenum,        //Aqua, Perditio
    Vesania,        //Cognitio, Vitium
    Victus,         //Aqua, Terra
    Vinculum,       //Motus, Perditio
    Vitium,         //Perditio, Praecantatio
    Vitreus,        //Terra, Ordo
    Volatus,        //Aer, Motus
    Caelum,         //Vitreus, Metallum
    NULL_ASPECT
};

const char* aspect_names[] = {
    "Aer", "Alienis", "Aqua", "Arbor", "Auram", "Bestia", "Cognitio", "Corpus",
    "Desidia", "Electrum", "Exanimis", "Fabrico", "Fames", "Gelum", "Gloria", "Gula",
    "Herba", "Humanus", "Ignis", "Infernus", "Instrumentum", "Invidia", "Ira", "Iter",
    "Limus", "Lucrum", "Lux", "Luxuria", "Machina", "Magneto", "Messis", "Metallum",
    "Meto", "Mortuus", "Motus", "Nebrisum", "Ordo", "Pannus", "Perditio", "Perfodio",
    "Permutatio", "Potentia", "Praecantatio", "Radio", "Sano", "Sensus", "Spiritus",
    "Strontio", "Superbia", "Telum", "Tempestas", "Tempus", "Tenebrae", "Terminus",
    "Terra", "Tutamen", "Vacuos", "Venenum", "Vesania", "Victus", "Vinculum", "Vitium",
    "Vitreus", "Volatus", "Caelum"
};

typedef struct graph{
    enum aspects aspect;
    struct graph **connection;
    int size;
    int count;
} graph;

graph* graph_lookup[MAX_NODES] = {NULL};

void create_node(enum aspects aspect){
    if (graph_lookup[aspect] == NULL) {
        graph_lookup[aspect] = (graph*) malloc(sizeof(graph));
        graph_lookup[aspect]->aspect = aspect;
        graph_lookup[aspect]->size = 2;
        graph_lookup[aspect]->count = 0;
        graph_lookup[aspect]->connection = (graph**) malloc(sizeof(graph*) * graph_lookup[aspect]->size);
    }
}

void grow_node(graph *node) {
    if (node->count >= node->size) {
        node->size *= 2;
        node->connection = (graph**) realloc(node->connection, sizeof(graph*) * node->size);
    }
}

void add_edge(graph *node1, graph *node2) {
    grow_node(node1);
    grow_node(node2);
    node1->connection[node1->count++] = node2;
    node2->connection[node2->count++] = node1;
}

void add_aspect(enum aspects parent, enum aspects child1, enum aspects child2) {
    create_node(parent);
    if (child1 != NULL_ASPECT) 
        add_edge(graph_lookup[parent], graph_lookup[child1]);

    if(child2 != NULL_ASPECT)
        add_edge(graph_lookup[parent], graph_lookup[child2]);
}

void populate() {
    //0
    add_aspect(Aer, NULL_ASPECT, NULL_ASPECT);
    add_aspect(Aqua, NULL_ASPECT, NULL_ASPECT);
    add_aspect(Ignis, NULL_ASPECT, NULL_ASPECT);
    add_aspect(Ordo, NULL_ASPECT, NULL_ASPECT);
    add_aspect(Perditio, NULL_ASPECT, NULL_ASPECT);
    add_aspect(Terra, NULL_ASPECT, NULL_ASPECT);

    //1
    add_aspect(Lux, Aer, Ignis);
    add_aspect(Motus, Aer, Ordo);
    add_aspect(Tempestas, Aer, Aqua);
    add_aspect(Vacuos, Aer, Perditio);
    add_aspect(Venenum, Aqua, Perditio);
    add_aspect(Victus, Aqua, Terra);
    add_aspect(Potentia, Ordo, Ignis);
    add_aspect(Vitreus, Terra, Ordo);
    add_aspect(Permutatio, Perditio, Ordo);
    add_aspect(Gelum, Ignis, Perditio);
    
    //2
    add_aspect(Radio, Potentia, Lux);
    add_aspect(Tempus, Vacuos, Ordo);
    add_aspect(Tenebrae, Vacuos, Lux);
    add_aspect(Praecantatio, Vacuos, Potentia);
    add_aspect(Iter, Motus, Terra);
    add_aspect(Bestia, Motus, Victus);
    add_aspect(Mortuus, Victus, Perditio);
    add_aspect(Vinculum, Motus, Perditio);
    add_aspect(Fames, Victus, Vacuos);
    add_aspect(Herba, Victus, Terra);
    add_aspect(Volatus, Aer, Motus);
    add_aspect(Metallum, Terra, Vitreus);
    add_aspect(Sano, Victus, Ordo);
    
    //3
    add_aspect(Arbor, Aer, Herba);
    add_aspect(Spiritus, Victus, Mortuus);
    add_aspect(Corpus, Mortuus, Bestia);
    add_aspect(Exanimis, Motus, Mortuus);
    add_aspect(Gula, Fames, Vacuos);
    add_aspect(Infernus, Ignis, Praecantatio);
    add_aspect(Auram, Praecantatio, Aer);
    add_aspect(Magneto, Metallum, Iter);
    add_aspect(Vitium, Perditio, Praecantatio);
    add_aspect(Superbia, Volatus, Vacuos);
    add_aspect(Alienis, Vacuos, Tenebrae);
    
    //4
    add_aspect(Cognitio, Ignis, Spiritus);
    add_aspect(Desidia, Vinculum, Spiritus);
    add_aspect(Sensus, Aer, Spiritus);
    add_aspect(Limus, Victus, Aqua);
    add_aspect(Luxuria, Corpus, Fames);
    
    //5
    add_aspect(Humanus, Bestia, Cognitio);
    add_aspect(Invidia, Sensus, Fames);
    add_aspect(Strontio, Perditio, Cognitio);
    add_aspect(Vesania, Cognitio, Vitium);
    
    //6
    add_aspect(Lucrum, Humanus, Fames);
    add_aspect(Gloria, Humanus, Iter);
    add_aspect(Instrumentum, Humanus, Ordo);
    add_aspect(Messis, Herba, Humanus);
    add_aspect(Perfodio, Humanus, Terra);

    //7
    add_aspect(Machina, Motus, Instrumentum);
    add_aspect(Fabrico, Humanus, Instrumentum);
    add_aspect(Telum, Instrumentum, Ignis);
    add_aspect(Nebrisum, Lucrum, Perfodio);
    add_aspect(Pannus, Instrumentum, Bestia);
    add_aspect(Terminus, Alienis, Lucrum);
    add_aspect(Tutamen, Instrumentum, Terra);

    //8
    add_aspect(Electrum, Potentia, Machina);
    add_aspect(Ira, Telum, Ignis);
    add_aspect(Meto, Messis, Nebrisum);
}

void print_graph() {
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph_lookup[i]) {
            printf("Aspect %d : ", i);
            for (int j = 0; j < graph_lookup[i]->count; j++)
                printf("%d ", graph_lookup[i]->connection[j]->aspect);
            printf("\n");
        }
    }
}

void print_path(graph **path, int length) {
    printf("Found path of length %d: ", length - 2);
    for (int i = 0; i < length; i++)
        printf("%s ", aspect_names[path[i]->aspect]);
    printf("\n");
}

short int dfs(graph *current, enum aspects goal, int remaining, graph **path, int depth) {
    path[depth] = current;

    if (remaining == 0) {
        if (current->aspect == goal) {
            print_path(path, depth + 1);
            return 1;
        }
        return 0;
    }

    for (int i = 0; i < current->count; i++) 
        if (dfs(current->connection[i], goal, remaining - 1, path, depth + 1))
            return 1;

    return 0;
}

void path(enum aspects aspect1, enum aspects aspect2, short int distance) {
    
    distance++;
    
    graph *start = graph_lookup[aspect1];
    graph *goal = graph_lookup[aspect2];
    
    if (!start || !goal) {
        printf("Invalid nodes\n");
        return ;
    }
    
    int max_search = 50;
    graph *temp_path[50];

    while (distance <= max_search) {
        if (dfs(start, aspect2, distance, temp_path, 0))
            return ;
        distance++;
    }

    printf("No path found within %d steps\n", max_search);
}

int aspect_lookup(char *aspect_name){
    for(int i = 0; i < MAX_NODES; i++)
        if(strcmp(aspect_name, aspect_names[i]) == 0)
            return i;
    return -1;
}

void cli(){
    populate();
}

void free_graph() {
    for (int i = 0; i < MAX_NODES; i++)
        if (graph_lookup[i]) {
            free(graph_lookup[i]->connection);
            free(graph_lookup[i]);
            graph_lookup[i] = NULL;
        }
}

int main()
{
    char aspect1[20], aspect2[20];
    int distance;

    cli();

    do {
        printf("Aspect 1: ");
        scanf("%s", aspect1);
        
        printf("Aspect 2: ");
        scanf("%s", aspect2);

        printf("Distance: ");
        scanf("%d", &distance);
        printf("\n");

        int aspect1_pos = aspect_lookup(aspect1);
        int aspect2_pos = aspect_lookup(aspect2);
        
        if(aspect1_pos == -1 || aspect2_pos == -1) {
            printf("Invalid node names\n");
        } else {
            path(aspect1_pos, aspect2_pos, distance); //path from aspect 1 to aspect 2
        }

        getchar();

        printf("\nTo exit enter q, else enter any other button\n");
        
    } while(getchar() != 'q');

    free_graph();
    return 0;
}
