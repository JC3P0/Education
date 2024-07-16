/**
 * Main.java - Driver class to demonstrate revised historical examples
 * 
 * @author ???
 * @version ???
 */

public class Main {
	public static void main(String[] args) {
		String tulsaDescription = "A black teenager, who was working as a shoe shiner in downtown Tulsa, Oklahoma, was arrested and accused of assaulting a white woman on a public elevator in broad daylight. A group of white vigilantes, intent on lynching him, and armed black men intent on protecting him gathered at the courthouse. A shot rang out, and the violence began. The riot resulted in 35 square blocks of destruction, including more than 1,250 homes, churches, schools, businesses, a hospital, and a library.";
		Date tulsaDay = new Date(5, 31, 1921);
		HistoricalEvent tulsaRiot = new HistoricalEvent(tulsaDescription, tulsaDay);
        // HistoricalEvent tulsaRiot = new HistoricalEvent(); //test

		System.out.println("====================================================");
		System.out.println("HISTORICAL EVENT EXAMPLE:");
		System.out.println("====================================================");
		System.out.println(tulsaRiot);
		
		// /*
        
		String tulsaRevised = "It started with newspaper reports that a black man had assaulted a white elevator operator. He was arrested, and black World War I vets rushed to the courthouse to prevent a lynching. Whites were deputized and handed weapons, the shooting started and then it got out of hand. It was mob rule for two days, and the result was the complete devastation of the entire black community. The white mobs looted the homes and businesses before they set fire to the community. Planes circled mid-air and bombed what was known as Black Wall Street. The National Guard was called out after the governor declared martial law, and imprisoned all blacks that were not already in jail. More than 35 blocks were destroyed, along with more than 1,200 homes, and some 300 people died, mostly Blacks.",
			tulsaCitation = "https://www.smithsonianmag.com/smithsonian-institution/long-lost-manuscript-contains-searing-eyewitness-account-tulsa-race-massacre-1921-180959251/";
		RevisedHistoricalEvent tulsaMassacre = new RevisedHistoricalEvent(tulsaDescription, tulsaDay,
			tulsaRevised, tulsaCitation);
        // RevisedHistoricalEvent tulsaMassacre = new RevisedHistoricalEvent();
		
		System.out.println("\n====================================================");
		System.out.println("REVISED HISTORICAL EVENT EXAMPLE:");
		System.out.println("====================================================");
		tulsaMassacre.teach();
        // System.out.println(tulsaMassacre);


        String civilWarDescription = "Ask most people why the US fought a civil war, and they’ll probably answer that the country was fighting over whether slavery should be legal. But even today, many schools in the Deep South teach students that the Civil War was about states’ rights and constitutional law.";
		Date civilWarDay = new Date(4, 12, 1861);
		HistoricalEvent civilWar = new HistoricalEvent(civilWarDescription, civilWarDay);
        // HistoricalEvent tulsaRiot = new HistoricalEvent(); //test

		System.out.println("====================================================");
		System.out.println("HISTORICAL EVENT EXAMPLE:");
		System.out.println("====================================================");
		System.out.println(civilWar);
        
        String civilWarRevised = "Unfortunately this seems to be an issue that is still happening. Slowly state by state changes are being made. Here are reasons why this will continue to be a slow process. \"With education a federal matter for the first time in history, Southern textbooks were written by authors who had previously served in the Confederate government. It became rather common for any Southerner who suggested that the Civil War had been about slavery to be subject to ridicule, unemployment, blackballing, and social shunning.\"",
			   civilWarCitation = "https://listverse.com/2016/01/05/10-insane-attempts-at-rewriting-history/";
		RevisedHistoricalEvent civilWarNeedsRevised = new RevisedHistoricalEvent(civilWarDescription, civilWarDay,
			civilWarRevised, civilWarCitation);
        // RevisedHistoricalEvent civilWarRevised = new RevisedHistoricalEvent();
		
		System.out.println("\n====================================================");
		System.out.println("REVISED HISTORICAL EVENT EXAMPLE:");
		System.out.println("====================================================");
		civilWarNeedsRevised.teach();
        
        // */
	}
}