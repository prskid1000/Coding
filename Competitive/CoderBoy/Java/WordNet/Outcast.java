public class Outcast {
    private final WordNet wordnet;

    // constructor takes a WordNet object
    public Outcast(WordNet wordnet) {
        this.wordnet = wordnet;
    }

    // given an array of WordNet nouns, return an outcast
    public String outcast(String[] nouns) {
        int distance = 0;
        String outcast = null;

        for (String i : nouns) {
            int d = 0;

            for (String j : nouns) {
                int dist = wordnet.distance(i, j);
                // StdOut.println("distance(" + i + "," + j + ") = " + dist);
                d += dist;
            }

            // StdOut.println("distance: " + d);

            if (d > distance) {
                distance = d;
                outcast = i;
            }

            // StdOut.println("distance: " + d + " outcast: " + outcast);
        }

        assert outcast != null;
        return outcast;
    }
}
