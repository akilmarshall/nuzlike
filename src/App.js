import React from 'react'
import { Button, Text, Grid } from '@nextui-org/react'
import { staticSpriteURL } from './PkmnInfo'
import { Link } from 'react-router-dom'


function App() {
    const pokemon = 1 + Math.floor((Math.random() * 386))
    return (
    <>
        <center>
            <h2>Nuzlike</h2>
        </center>
        <center>
            <img src={staticSpriteURL(pokemon)} alt=""/>
        </center>
        <center>
            <Text>Your favorite <b>Nuz</b>locke experience without any of the awful grinding and instead emphasis on the rogue<b>like</b> elements.</Text>
        </center>
        <center>
        <Grid.Container alignItems='center' direction='column' gap={1}>
            <Grid xs={2}>
                <Button flat color='primary'>
                    <Link to="/choose-starter" as={Button}>Start</Link>
                </Button>
            </Grid>
            <Grid xs={2}>
                <Button flat color='primary'>
                    <Link to="/settings" as={Button}>Settings</Link>
                </Button>
            </Grid>
            <Grid xs={2}>
                <Button flat color='primary'>
                    <Link to="/about" as={Button}>About</Link>
                </Button>
            </Grid>
        </Grid.Container>
        </center>
    </>
    );
}

export default App;
