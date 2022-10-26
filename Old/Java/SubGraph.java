import java.util.*;
import java.util.Arrays;
import java.io.*;
import java.util.Set;
import java.util.HashMap;
import java.util.HashSet;
import java.lang.*;
//Class for the Subgraph
public class SubGraph{
	public static void main(String[] args) throws Exception{
		// Create graph object using provided file
		Graph graph=new Graph(args[0]," ");
		// display the graph
		StdOut.println("The graph is");
		StdOut.print(graph);
		// create a map to track the vertices of sub-graph
		HashMap<String, Boolean> subVerticesMap = new HashMap<String, Boolean>();
		for(int i=1;i<args.length;i++){
			subVerticesMap.put(args[i], true);
		}

		// print out subgraph by iterating over vertices and edges
		StdOut.println("The subgraph is");
		// iterate over all the vertices of the graph
		for(String v : graph.vertices()){
			// check if current vertex is present in the sub-graph
			if(subVerticesMap.containsKey(v)){
				StdOut.print(v+":");
				// iterate over adjacent vertex of current vertex
				for(String w: graph.adjacentTo(v)){
					if(subVerticesMap.containsKey(w)){
						// if adjacent vertex is present in the sub-graph, print it
						StdOut.print(" " + w);
					}
				}
				StdOut.println();
			}
		}
	}
}