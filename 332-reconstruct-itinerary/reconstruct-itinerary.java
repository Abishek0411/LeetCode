class Solution {
    private Map<String, List<String>> flightGraph;
    private List<String> itinerary;
    public Solution() {
        flightGraph = new HashMap<>();
        itinerary = new ArrayList<>();
    }
    private void dfs(String airport) {
        List<String> destinations = flightGraph.get(airport);
        while (destinations != null && !destinations.isEmpty()) {
            String nextDestination = destinations.remove(destinations.size() - 1);
            dfs(nextDestination);
        }
        itinerary.add(airport);
    }
    public List<String> findItinerary(List<List<String>> tickets) {
        for (List<String> ticket : tickets) {
            String from = ticket.get(0);
            String to = ticket.get(1);
            flightGraph.computeIfAbsent(from, k -> new ArrayList<>()).add(to);
        }
        for (List<String> destinations : flightGraph.values()) {
            destinations.sort(Collections.reverseOrder());
        }
    dfs("JFK");
    Collections.reverse(itinerary);
    return itinerary;
    }
}