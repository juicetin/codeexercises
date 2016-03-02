import java.io.*;
import java.util.*;

class StartWithRange {
    public StartWithRange(){}
    public int start;
    public int range;
}

class XAndHisShots {
    public static boolean playerCanCatchShot(StartWithRange shotInfo, StartWithRange playerInfo) {
        int diff = shotInfo.start - playerInfo.start;
        return diff <= playerInfo.range && diff >= 0;
    }

    public static int totalStrength(StartWithRange[] shots, StartWithRange[] players) {
        int totalStrength = 0;
        for (StartWithRange player : players) {
            // int playerStrength = 0;
            for (StartWithRange shot : shots) {
                if (playerCanCatchShot(shot, player)) {
                    totalStrength++;
                }
            }
        }
        return totalStrength;
    }

    public static void main (String args[]) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int shotCount, playerCount;
            String input = br.readLine();
            shotCount = Integer.parseInt(input.split(" ")[0]);
            playerCount = Integer.parseInt(input.split(" ")[1]);

            StartWithRange shots[] = new StartWithRange[shotCount];
            StartWithRange players[] = new StartWithRange[playerCount];

            for (int i = 0; i < shotCount; ++i) {
                input = br.readLine();
                StartWithRange shot = new StartWithRange();
                shot.start = Integer.parseInt(input.split(" ")[0]);
                shot.range = Integer.parseInt(input.split(" ")[1]);
                shots[i] = shot;
            }

            for (int i = 0; i < playerCount; ++i) {
                input = br.readLine();
                StartWithRange player = new StartWithRange();
                player.start = Integer.parseInt(input.split(" ")[0]);
                player.range = Integer.parseInt(input.split(" ")[1]);
                players[i] = player;
            }

            int totalStrength = totalStrength(shots, players);
            System.out.println(totalStrength);
        } catch(IOException i) {}
    }
}

