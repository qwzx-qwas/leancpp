const int MaxSize = 1000;
typedef struct {
    int data[MaxSize];
    int last;  // last index of the array
} Seqset;

Seqset Intersection(Seqset a, Seqset b) {
    Seqset c;
    c.last = -1;  // Initialize last index
    int i = 0, j = 0;

    while (i <= a.last && j <= b.last) {
        if (a.data[i] < b.data[j]) {
            i++;
        } else if (a.data[i] > b.data[j]) {
            j++;
        } else {
            c.data[++c.last] = a.data[i];
            i++;
            j++;
        }
    }
    return c;
}

Seqset Union(Seqset a, Seqset b) {
    Seqset c;
    c.last = -1;  // Initialize last index
    int i = 0, j = 0;

    while (i <= a.last && j <= b.last) {
        if (a.data[i] < b.data[j]) {
            c.data[++c.last] = a.data[i++];
        } else if (a.data[i] > b.data[j]) {
            c.data[++c.last] = b.data[j++];
        } else {
            c.data[++c.last] = a.data[i++];
            j++;
        }
    }

    while (i <= a.last) {
        c.data[++c.last] = a.data[i++];
    }
    while (j <= b.last) {
        c.data[++c.last] = b.data[j++];
    }

    return c;
}

Seqset difference(Seqset a, Seqset b) {
    Seqset c;
    c.last = -1;  // Initialize last index
    int i = 0, j = 0;

    while (i <= a.last && j <= b.last) {
        if (a.data[i] < b.data[j]) {
            c.data[++c.last] = a.data[i++];
        } else if (a.data[i] > b.data[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (i <= a.last) {
        c.data[++c.last] = a.data[i++];
    }

    return c;
}
