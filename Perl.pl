use strict;
use warnings;
use utf8;

#read file
my $f = $ARGV[0];
my $count = 0;

open(my $fh, "<", $f) || die "Couldn't open '".$f."' for reading because: ".$!;

my @arr = (0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

while(my $line = readline $fh) {

	my $date = undef;

	if($line =~ m/[0-9]{2}\/May\/2015/ && $line =~ m/ 200 /){
		$line =~ m/([0-9]{2})\/May\/2015/;
		$date = $1 - 1;
		$arr[$date] = $arr[$date] + 1;
	}
	
}

@arr  = sort(@arr);

print "MAX = $arr[-1]\n"; #MAX

#while($arr[$count] == 0){
#	$count = $count + 1;
#}

print "MIN = $arr[0]\n"; #MIN

print "MEDIAN = $arr[15]\n"; #MEDIAN

for( my $a = 0; $a < 31; $a = $a + 1 ){
	$count = $count + $arr[$a];
}

my $avg = $count/31;

print "AVERAGE = $avg\n"; #AVG

$count = 0;

for( $a = 0; $a < 31; $a = $a + 1 ){
	$count = $count + ($arr[$a]-$avg)**2;
}

my $std = sqrt($count/31);

print "STANDARD DEVIATION = $std\n"; #STD
