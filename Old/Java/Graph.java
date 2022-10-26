import java.util.*;
import java.io.*;
import java.util.Set;
import java.util.HashMap;
import java.util.HashSet;
import java.lang.*;
class Graph{
	// symbol table: key = string vertex, value = set of neighboring vertices
	private HashMap<String,Set<String>> st;
	// number of edges
	private int E;
	/**
	* Initializes an empty graph with no vertices or edges.
	*/
	public Graph(){
		st=new HashMap<String,Set<String>>();
	}
	/**
	* Initializes a graph from the specified file, using the specified delimiter.
	*
	* @param filename the name of the file
	* @param delimiter the delimiter
	*/
	public Graph(String filename , String delimiter) throws Exception{
		File file=new File(filename);
		st=new HashMap<String,Set<String>>();
		In in=new In(file);
		while(in.hasNextLine()){
			String line=in.readLine();
			String[] names=line.split(delimiter);
			for(int i=1;i<names.length;i++){
				addEdge(names[0],names[i]);
			}
		}
	}
	/**
	* Returns the number of vertices in this graph.
	*
	* @return the number of vertices in this graph
	*/
	public int V(){
		return st.size();
	}
	/**
	* Returns the number of edges in this graph.
	*
	* @return the number of edges in this graph
	*/
	public int E(){
		return E ;
	}
	// throw an exception if v is not a vertex
	private void validateVertex(String v){
		if(!hasVertex(v)) throw new IllegalArgumentException ( v + " is not a vertex" );
	}
	/**
	* Returns the degree of vertex v in this graph.
	*
	* @param v the vertex
	* @return the degree of { @code v} in this graph
	* @throws IllegalArgumentException if { @code v} is not a vertex in this graph
	*/
	public int degree(String v){
		validateVertex(v);
		return st.get(v).size();
	}
	/**
	* Adds the edge v-w to this graph (if it is not already an edge).
	*
	* @param v one vertex in the edge
	* @param w the other vertex in the edge
	*/
	public void addEdge(String v,String w){
		if(!hasVertex(v)) addVertex(v);
		if(!hasVertex(w)) addVertex(w);
		if(!hasEdge(v,w)) E++;
		st.get(v).add(w);
		st.get(w).add(v);
	}
	/**
	* Adds vertex v to this graph (if it is not already a vertex).
	*
	* @param v the vertex
	*/
	public void addVertex(String v){
		if(!hasVertex(v)) st.put(v,new HashSet<String>());
	}
	/**
	* Returns the vertices in this graph.
	*
	* @return the set of vertices in this graph
	*/
	public Iterable<String> vertices(){
		return st.keySet();
	}
	/**
	* Returns the set of vertices adjacent to v in this graph.
	*
	* @param v the vertex
	* @return the set of vertices adjacent to vertex { @code v} in this graph
	* @throws IllegalArgumentException if { @code v} is not a vertex in this graph
	*/
	public Iterable<String> adjacentTo(String v){
		validateVertex(v);
		return st.get (v);
	}
	/**
	* Returns true if v is a vertex in this graph.
	*
	* @param v the vertex
	* @return { @code true} if { @code v} is a vertex in this graph,
	* { @code false} otherwise
	*/
	public boolean hasVertex(String v){
		return st.containsKey(v);
	}
	public String get(String v){
		return v;
	}
	/**
	* Returns true if v-w is an edge in this graph.
	*
	* @param v one vertex in the edge
	* @param w the other vertex in the edge
	* @return { @code true} if { @code v-w} is a vertex in this graph,
	* { @code false} otherwise
	* @throws IllegalArgumentException if either { @code v} or { @code w}
	* is not a vertex in this graph
	*/
	public boolean hasEdge(String v,String w){
		validateVertex(v);
		validateVertex(w);
		return st.get(v).contains(w);
	}
	/**
	* Returns a string representation of this graph.
	*
	* @return string representation of this graph
	*/
	public String toString(){
		StringBuilder s = new StringBuilder();
		for (String v : st.keySet()){
			s.append(v+": ");
			for(String w : st.get(v)){
				s.append(w+" ");
			}
			s.append('\n');
		}
		return s.toString();
	}
	/**
	* Unit tests the { @code Graph} data type.
	*
	* @param args the command-line arguments
	*/
	public static void main(String[] args) throws Exception{
	// create graph
		Graph graph=new Graph();
		// print out graph
		Graph graph1=new Graph(args[0]," ");
		System.out.println(graph1);
		int j=0;
		String[] sub_vertices=new String[args.length-1];
		for(int i=1;i<args.length;i++){
			sub_vertices[j++]=args[i];
		} 
		for(int i=0;i<sub_vertices.length;i++){
			System.out.println(sub_vertices[i]);
		}
		// print out graph again by iterating over vertices and edges
		/**
		for(String v : graph.vertices()){
			System.out.print(v+": ");
			for(String w : graph.adjacentTo(v)){
				System.out.print(w+" ");
			}
			System.out.println();
		}
		*/
	}
}